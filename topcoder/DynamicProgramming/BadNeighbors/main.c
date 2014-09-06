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
/* http://community.topcoder.com/stat?c=problem_statement&pm=2402&rd=5009 */

/* test data */
/* 0)	 */
/*  { 10, 3, 2, 5, 7, 8 } */
/* Returns: 19 */
/* The maximum donation is 19, achieved by 10+2+7. It would be better to take 10+5+8 except that the 10 and 8 donations are from neighbors. */

/* 1)	 */
/* { 11, 15 } */
/* Returns: 15 */

/* 2)	 */
/* { 7, 7, 7, 7, 7, 7, 7 } */
/* Returns: 21 */

/* 3)	 */
/* { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 } */
/* Returns: 16 */

/* 4)	 */
/* { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,   */
/*   6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, */
/*   52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 } */
/* Returns: 2926 */

#define TEST_DATA_0 { 10, 3, 2, 5, 7, 8 }
#define TEST_DATA_1 { 11, 15 }
#define TEST_DATA_2 { 7, 7, 7, 7, 7, 7, 7 }
#define TEST_DATA_3 { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 }
#define TEST_DATA_4 { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,\
  6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,\
  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_int_array(int array[],int size)
{
    printf("array : \n");
    printf("begin----------------\n");
    int i;
    for(i=0; i!=size; ++i)
    {
	printf("%d ",array[i]);
    }
    printf("\nend----------------\n");
}

static int * f_list;

int maxDp(int data[],int size)
{
    /* print_int_array(data,size); */
    int ret = -1;
    if(-1 != *(f_list+size-1)){
    	return *(f_list+size-1);
    }
    
    if(1 == size){
	ret = data[0];
    }else if(2 == size){
	ret = data[0] > data[1] ? data[0] : data[1];
    }else if(3 == size){
	int max = data[0] + data[2];;
	max = max > data[1] ? max : data[1];
	ret = max;
    }else{
	int ret1 = maxDp(data,size-2) + data[size-1];
	int ret2 = maxDp(data,size-1);
	ret = ret1 > ret2 ? ret1 : ret2;
    }
    /* printf("ret == %d\n",ret); */
    *(f_list+size-1) = ret;
    return ret;
}

int maxDonations(int data[],int size)
{
    f_list = malloc(sizeof(int)*size);
    memset(f_list,-1,sizeof(int)*size);
    int ret1 = maxDp(data,size-1);
    int ret2 = maxDp(data+1,size-1);
    int ret = ret1 > ret2 ? ret1 : ret2;
    free(f_list);
    return ret;
}

int main(int argc,char ** argv)
{
    printf("bad neighbours\n");

    int data0[] = TEST_DATA_0;
    int ret = maxDonations(data0,sizeof(data0)/sizeof(int));
    printf("result = %d\n",ret);
    
    int data1[] = TEST_DATA_1;
    ret = maxDonations(data1,sizeof(data1)/sizeof(int));
    printf("result = %d\n",ret);

    int data2[] = TEST_DATA_2;
    ret = maxDonations(data2,sizeof(data2)/sizeof(int));
    printf("result = %d\n",ret);

    int data3[] = TEST_DATA_3;
    ret = maxDonations(data3,sizeof(data3)/sizeof(int));
    printf("result = %d\n",ret);

    int data4[] = TEST_DATA_4;
    ret = maxDonations(data4,sizeof(data4)/sizeof(int));
    printf("result = %d\n",ret);
    
    return 0;
}
