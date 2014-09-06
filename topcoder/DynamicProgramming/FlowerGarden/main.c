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
/* http://community.topcoder.com/stat?c=problem_statement&pm=1918&rd=5006 */

/* test data */

/* 0)	 */
#define TEST_HEIGHT_0 {5,4,3,2,1}
#define TEST_BLOOM_0 {1,1,1,1,1}
#define TEST_WILT_0 {365,365,365,365,365}
/* Returns: { 1,  2,  3,  4,  5 } */
/* These flowers all bloom on January 1st and wilt on December 31st. Since they all may block each other, you must order them from shortest to tallest. */
	
/* 1)	 */
#define TEST_HEIGHT_1 {5,4,3,2,1}
#define TEST_BLOOM_1 {1,5,10,15,20}
#define TEST_WILT_1 {4,9,14,19,24}
/* Returns: { 5,  4,  3,  2,  1 } */
/* The same set of flowers now bloom all at separate times. Since they will never block each other, you can order them from tallest to shortest to get the tallest ones as far forward as possible. */
	
/* 2)	 */
#define TEST_HEIGHT_2 {5,4,3,2,1}
#define TEST_BLOOM_2 {1,5,10,15,20}
#define TEST_WILT_2 {5,10,15,20,25}
/* Returns: { 1,  2,  3,  4,  5 } */
/* Although each flower only blocks at most one other, they all must be ordered from shortest to tallest to prevent any blocking from occurring. */
	
/* 3)	 */
#define TEST_HEIGHT_3 {5,4,3,2,1}
#define TEST_BLOOM_3 {1,5,10,15,20}
#define TEST_WILT_3 {5,10,14,20,25}
/* Returns: { 3,  4,  5,  1,  2 } */
/* The difference here is t
   hat the third type of flower wilts one day earlier than the blooming of the fourth flower. Therefore, we can put the flowers of height 3 first, then the flowers of height 4, then height 5, and finally the flowers of height 1 and 2. Note that we could have also ordered them with height 1 first, but this does not result in the maximum possible height being first in the garden. */
	
/* 4)	 */
#define TEST_HEIGHT_4 {1,2,3,4,5,6}
#define TEST_BLOOM_4 {1,3,1,3,1,3}
#define TEST_WILT_4 {2,4,2,4,2,4}
/* Returns: { 2,  4,  6,  1,  3,  5 } */

/* 5)	 */
#define TEST_HEIGHT_5 {3,2,5,4}
#define TEST_BLOOM_5 {1,2,11,10}
#define TEST_WILT_5 {4,3,12,13}
/* Returns: { 4,  5,  2,  3 } */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_int_array(int *array,int size)
{
    printf("array : \n");
    printf("begin----------------\n");
    int i;
    for(i=0; i!=size; ++i)
    {
	printf("%d ",*(array+i));
    }
    printf("\nend----------------\n");
}

/* define push_back : */
/* Put an element described by height[index] , bloomi[index, wilt[index], into an ordered array des with size elements. */
void push_back(int *des,int size, int const *height,int const *bloom, int const *wilt,int index)
{
    if(0==size){
	*des = index;
	return;
    }else{
	int i;
	for(i=size-1;i>=0;--i)
	{
	    /* if A(index) has conflict in blooming period with A(i) */
	    if(*(wilt+*(des+i)) < *(bloom+index)
	       || *(bloom+*(des+i)) > *(wilt+index)){
	    }else{
		break;
	    }
	}
	/* printf("size - 1 == %d\n",size-1); */

	/* if Ai is taller than  Aj */
	if(-1!=i && *(height+index) < *(height+*(des+i))){
	    int j;
	    for(j=size;j>i;--j)
	    {
		*(des+j) = *(des+j-1);
	    }
	    *(des+i) = index;
	    push_back(des,i,height,bloom,wilt,index);
	    return;
	}else{
	    /* place Ai into j ~ i-1 */
	    int j;
	    for(j=size-1;j>i;--j)
	    {
		if(*(height+index) < *(height+*(des+j))){
		    break;
		}
	    }
	    /* insert Ai at j */
	    int k;
	    for(k=size;k>j+1;--k)
	    {
		*(des+k) = *(des+k-1);
	    }
	    *(des+j+1) = index;
	    return;
	}
    }
}

int* getOrdering(int *height,int *bloom,int *wilt,int size)
{
    int *ret_index = malloc(sizeof(int)*size);
    memset(ret_index,0,sizeof(int)*size);

    int i;
    /* ret_index is an array which store index of each flower listed in height array */
    for(i=0;i<size;++i)
    {
    	push_back(ret_index,i,height,bloom,wilt,i);
    }
    
    /* translate the index array to height array */
    for(i=0;i<size;++i)
    {
    	*(ret_index+i) = *(height+*(ret_index+i));
    }
    
    return ret_index;
}

int main(int argc,char ** argv)
{
    printf("flower garden\n");

    int size=0;
    int *ret=NULL;
    
    int test_height_0[] = TEST_HEIGHT_0;
    int test_bloom_0[] = TEST_BLOOM_0;
    int test_wilt_0[] = TEST_WILT_0;
    size = sizeof(test_height_0)/sizeof(int);
    ret = getOrdering(test_height_0,test_bloom_0,test_wilt_0,size);
    print_int_array(ret,size);
    free(ret);

    int test_height_1[] = TEST_HEIGHT_1;
    int test_bloom_1[] = TEST_BLOOM_1;
    int test_wilt_1[] = TEST_WILT_1;
    size = sizeof(test_height_1)/sizeof(int);
    ret = getOrdering(test_height_1,test_bloom_1,test_wilt_1,size);
    print_int_array(ret,size);
    free(ret);

    int test_height_2[] = TEST_HEIGHT_2;
    int test_bloom_2[] = TEST_BLOOM_2;
    int test_wilt_2[] = TEST_WILT_2;
    size = sizeof(test_height_2)/sizeof(int);
    ret = getOrdering(test_height_2,test_bloom_2,test_wilt_2,size);
    print_int_array(ret,size);
    free(ret);

    int test_height_3[] = TEST_HEIGHT_3;
    int test_bloom_3[] = TEST_BLOOM_3;
    int test_wilt_3[] = TEST_WILT_3;
    size = sizeof(test_height_3)/sizeof(int);
    ret = getOrdering(test_height_3,test_bloom_3,test_wilt_3,size);
    print_int_array(ret,size);
    free(ret);

    int test_height_4[] = TEST_HEIGHT_4;
    int test_bloom_4[] = TEST_BLOOM_4;
    int test_wilt_4[] = TEST_WILT_4;
    size = sizeof(test_height_4)/sizeof(int);
    ret = getOrdering(test_height_4,test_bloom_4,test_wilt_4,size);
    print_int_array(ret,size);
    free(ret);

    int test_height_5[] = TEST_HEIGHT_5;
    int test_bloom_5[] = TEST_BLOOM_5;
    int test_wilt_5[] = TEST_WILT_5;
    size = sizeof(test_height_5)/sizeof(int);
    ret = getOrdering(test_height_5,test_bloom_5,test_wilt_5,size);
    print_int_array(ret,size);
    free(ret);

    return 0;
}
