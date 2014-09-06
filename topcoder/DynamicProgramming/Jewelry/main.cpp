/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/04/18 16:56:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TerryLu (), terrylu87@gmail.com
 *        Company:  TerryLu's working house
 *
 * =====================================================================================
 */

/* This is a problem from top coder */
/* http://community.topcoder.com/stat?c=problem_statement&pm=1166&rd=4705 */

/* test data */
/* 0)	 */
#define TEST_DATA_0 {1,2,5,3,4,5}
/* Returns: 9 */
/* From above. */

/* 1)	 */
// #define TEST_DATA_1 {1000,1000,1000,1000,1000}
#define TEST_DATA_1 {1000,1000,1000,1000,1000,\
		1000,1000,1000,1000,1000,     \
		1000,1000,1000,1000,1000,     \
		1000,1000,1000,1000,1000,     \
		1000,1000,1000,1000,1000,     \
		1000,1000,1000,1000,1000}
/* Returns: 18252025766940 */
// 18252025766940
// 203262966994020
// 59132290782430711

/* 2)	 */
#define TEST_DATA_2 {1,2,3,4,5}
/* Returns: 4 */
/* Valid allocations: */
/* Bob               Frank */
/* 1,2                 3 */
/* 2,3                 5 */
/* 1,3                 4 */
/* 1,4                 5 */

/* 3)	 */
#define TEST_DATA_3 {7,7,8,9,10,11,1,2,2,3,4,5,6}
/* Returns: 607 */

/* 4)	 */
#define TEST_DATA_4 {123,217,661,678,796,964,54,111,417,526,917,923}
/* Returns: 0 */

// 5)
// I create a test data my own, calculate by hand, analyse the process and then abstract it into algorithm.
#define TEST_DATA_5 {1,1,2,2,3}
// Returns: 10


#include <stdio.h>
#include <stdlib.h>
#include <tr1/unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

void print_map(map<int, int > &m)
{
    map<int, int >::const_iterator it;
    for(it=m.begin();it!=m.end();++it)
    {
	cout << it->first << ":" << it->second << " ";
    }
    cout << endl;
}

void print_hash(tr1::unordered_map<long long,long long> &h)
{
    tr1::unordered_map<long long,long long>::const_iterator it;
    for(it=h.begin();it!=h.end();++it)
    {
	cout << it->first << "," << it->second << " | ";;
    }
    cout << endl;
}

long long n_choose_k(  long long n,  long long k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    long long result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

long long howMany(int* values,int size)
{
    long long ret=0;
    map<int,int > m_val;
    int i,j,k;

    // init map which stores the values
    for(i=0;i<size;++i)
    {
    	m_val[*(values+i)] += 1;
    }

    // print_map(m_val);

    tr1::unordered_map<long long,long long> h_sum_b[size];
    tr1::unordered_map<long long,long long> h_sum_f[size];
    
    tr1::unordered_map<long long, long long>::const_iterator ith;
    map<int,int>::const_iterator itm;
    map<int,int>::const_reverse_iterator ritm;

    // create the table of Bob
    // for each group of value
    i=0;
    for(itm = m_val.begin(); itm != m_val.end(); ++itm)
    {
	// for each value in group
	for(j=0; j < itm->second; ++j)
	{
	    if(i==size-1){
	    	break;
	    }
	    // elements count == j+1
	    h_sum_b[i+j][itm->first*(j+1)] += n_choose_k(itm->second,j+1);
	    // for each h_sum_b before this one (0~i-1)
	    for(k=0;k<i;++k)
	    {
		// for each value in that h_sum_b[k]
		for(ith = h_sum_b[k].begin(); ith != h_sum_b[k].end(); ++ith)
		{
		    // calculate this value
		    h_sum_b[i+j][ith->first+itm->first*(j+1)] += (ith->second * n_choose_k(itm->second,j+1) );
		}
	    }
	}
	i+=itm->second;
    }

    // create the table of Frank
    // process last group of value
    ritm = m_val.rbegin();
    h_sum_f[size-1][ritm->first] += 1;
    if(1 < ritm->second ){
    	// for every value in last group expect last value
    	for(i=0;i<ritm->second-1;++i)
    	{
	    if(i==size-2){
	    	break;
	    }
	    int index = size-2-i;
    	    h_sum_f[index][ritm->first] += 1;
    	    // for every sum in previous map
    	    for(ith=h_sum_f[index+1].begin();
    	    	ith!=h_sum_f[index+1].end();
    	    	++ith)
    	    {
    	    	h_sum_f[index][ritm->first+ith->first] += ith->second;
		h_sum_f[index][ith->first] += ith->second;
    	    }
    	}
    }
    // process other values
    i=size-1-ritm->second;
    ++ritm;
    while(i>0 && ritm != m_val.rend()){
    	// cout << "i == " << i << endl;
    	// cout << "ritm : " << ritm->first << ": " << ritm->second << endl;
    	// for each value in group
    	for(j=0; j < ritm->second; ++j)
    	{
	    if(i==0){
		break;
	    }
    	    h_sum_f[i][ritm->first] += 1;
    	    for(ith = h_sum_f[i+1].begin(); ith != h_sum_f[i+1].end(); ++ith)
    	    {
    		h_sum_f[i][ith->first+ritm->first] += ith->second;
    		h_sum_f[i][ith->first] += ith->second;
    	    }
    	    --i;
    	}
    	++ritm;
    }

    // calculate the result
    i=0;
    for(itm=m_val.begin();itm!=m_val.end();++itm)
    {
	for(j=0;j<itm->second;++j)
	{
	    if(i+j+1 == size){
		break;
	    }
	    for(ith=h_sum_b[i+j].begin();ith!=h_sum_b[i+j].end();++ith)
	    {
		if(h_sum_f[i+j+1].find(ith->first) != h_sum_f[i+j+1].end()){
		    ret += ith->second * h_sum_f[i+j+1][ith->first];
		}
	    }
	}
	i += itm->second;
    }
    
    // print two sum tables
    // for(i=0;i<size;++i)
    // {
    // 	print_hash(h_sum_b[i]);
    // }

    // printf("-------------------------\n");

    // for(i=0;i<size;++i)
    // {
    // 	print_hash(h_sum_f[i]);
    // }

    return ret;
}

// only for testing special array which contains only one value in it
// for example test data 1
long long calculate_mono(int num)
{
    long long ret=0;
    int i=0;
    for(i=2;i<=num;i+=2)
    {
    	ret += n_choose_k(num,i/2)*n_choose_k(num-i/2,i/2);
    }
    return ret;
}

int main(int argc,char ** argv)
{
    printf("Jewelry\n");

    long long ret=0;
    
    int test_data_0[] = TEST_DATA_0;
    ret = howMany(test_data_0,sizeof(test_data_0)/sizeof(int));
    printf("ret == %lld\n", ret);

    int test_data_1[] = TEST_DATA_1;
    ret = howMany(test_data_1,sizeof(test_data_1)/sizeof(int));
    printf("ret == %lld\n", ret);

    int test_data_2[] = TEST_DATA_2;
    ret = howMany(test_data_2,sizeof(test_data_2)/sizeof(int));
    printf("ret == %lld\n", ret);

    int test_data_3[] = TEST_DATA_3;
    ret = howMany(test_data_3,sizeof(test_data_3)/sizeof(int));
    printf("ret == %lld\n", ret);

    int test_data_4[] = TEST_DATA_4;
    ret = howMany(test_data_4,sizeof(test_data_4)/sizeof(int));
    printf("ret == %lld\n", ret);

    int test_data_5[] = TEST_DATA_5;
    ret = howMany(test_data_5,sizeof(test_data_5)/sizeof(int));
    printf("ret == %lld\n", ret);

    return 0;
}

