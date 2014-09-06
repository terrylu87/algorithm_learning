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
 *        Company:  vlctech
 *
 * =====================================================================================
 */

/* This is a problem from top coder */
/* http://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493 */

/* test data */

/* 0)	 */
/* { 1, 7, 4, 9, 2, 5 } */
/* Returns: 6 */
/* The entire sequence is a zig-zag sequence. */

/* 1)	 */
/* { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 } */
/* Returns: 7 */
/* There are several subsequences that achieve this length. One is 1,17,10,13,10,16,8. */

/* 2)	 */
/* { 44 } */
/* Returns: 1 */

/* 3)	 */
/* { 1, 2, 3, 4, 5, 6, 7, 8, 9 } */
/* Returns: 2 */

/* 4)	 */
/* { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 } */
/* Returns: 8 */

/* 5)	 */
/* { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,  */
/* 600, 947, 978, 46, 100, 953, 670, 862, 568, 188,  */
/* 67, 669, 810, 704, 52, 861, 49, 640, 370, 908,  */
/* 477, 245, 413, 109, 659, 401, 483, 308, 609, 120,  */
/* 249, 22, 176, 279, 23, 22, 617, 462, 459, 244 } */
/* Returns: 36 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_DATA_0 { 1, 7, 4, 9, 2, 5 }
#define TEST_DATA_1 { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }
#define TEST_DATA_2 { 44 }
#define TEST_DATA_3 { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
#define TEST_DATA_4 { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }
#define TEST_DATA_5 { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,\
600, 947, 978, 46, 100, 953, 670, 862, 568, 188,\
67, 669, 810, 704, 52, 861, 49, 640, 370, 908,\
477, 245, 413, 109, 659, 401, 483, 308, 609, 120,\
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 }

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

int longestZigZag(int sequence[],int size)
{
    printf("\nsize of sequence : %d\n",size);

    if(1 == size)
	return 1;
    
    int longest_length=1;

    int i=0;
    
    int diff_array[size-1];

    for(i=0;i<size-1;++i)
    {
	diff_array[i] = sequence[i+1] - sequence[i];
    }

    print_int_array(diff_array,sizeof(diff_array)/sizeof(int));

    int last_num = diff_array[0];
    for(i=1; i!=size-1; ++i)
    {
	if(diff_array[i] != 0){
	    if(diff_array[i]*last_num < 0){
		longest_length++;
	    }
	    last_num = diff_array[i];
	}
    }
    
    return longest_length+1;
}

int main(int argc,char ** argv)
{
    printf("zigzag\n");

    int test_data_0[] = TEST_DATA_0;
    int result = longestZigZag(test_data_0,sizeof(test_data_0)/sizeof(int));
    printf("result = %d\n",result);
    
    int test_data_1[] = TEST_DATA_1;
    result = longestZigZag(test_data_1,sizeof(test_data_1)/sizeof(int));
    printf("result = %d\n",result);

    int test_data_2[] = TEST_DATA_2;
    result = longestZigZag(test_data_2,sizeof(test_data_2)/sizeof(int));
    printf("result = %d\n",result);

    int test_data_3[] = TEST_DATA_3;
    result = longestZigZag(test_data_3,sizeof(test_data_3)/sizeof(int));
    printf("result = %d\n",result);

    int test_data_4[] = TEST_DATA_4;
    result = longestZigZag(test_data_4,sizeof(test_data_4)/sizeof(int));
    printf("result = %d\n",result);
    
    int test_data_5[] = TEST_DATA_5;
    result = longestZigZag(test_data_5,sizeof(test_data_5)/sizeof(int));
    printf("result = %d\n",result);
    
    return 0;
}
