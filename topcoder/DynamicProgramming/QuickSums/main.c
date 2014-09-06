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
/* http://community.topcoder.com/stat?c=problem_statement&pm=2829&rd=5072 */

/* test data */
/* 0) */
#define TEST_NUM_0 "99999"
#define TEST_SUM_0 45
/* Returns: 4 */
/* In this case, the only way to achieve 45 is to add 9+9+9+9+9. This requires 4 additions. */

/* 1)	 */
#define TEST_NUM_1 "1110"
#define TEST_SUM_1 3
/* Returns: 3 */
/* Be careful with zeros. 1+1+1+0=3 and requires 3 additions. */

/* 2)	 */
#define TEST_NUM_2 "0123456789"
#define TEST_SUM_2 45
/* Returns: 8 */

/* 3)	 */
#define TEST_NUM_3 "99999"
#define TEST_SUM_3 100
/* Returns: -1 */

/* 4)	 */
#define TEST_NUM_4 "382834"
#define TEST_SUM_4 100
/* Returns: 2 */
/* There are 3 ways to get 100. They are 38+28+34, 3+8+2+83+4 and 3+82+8+3+4. The minimum required is 2. */

/* 5)	 */
#define TEST_NUM_5 "9230560001"
#define TEST_SUM_5 71
/* Returns: 4 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    int adNum;
    int lastAdPos;
}AdData;

#define INFINITE 999

int minSums(char* numbers, int sum)
{
    int ret=-1;
    int i,j;
    
    int len = strlen(numbers);
    /* printf("strlen == %d\n", len); */

    /* transfer the numbers into int digits */
    int digit[len];
    for(i=0;i<len;++i)
    {
	digit[i] = *(numbers+i) - '0';
    }
    /* print the init digits */
    /* printf("----------\n"); */
    /* for(i=0;i<len;++i) */
    /* { */
    /* 	printf("%d ",digit[i]); */
    /* } */
    /* printf("\n----------\n"); */


    AdData NO_DATA = {INFINITE,INFINITE};
    /* minTable[use i digit][sum] = use min k '+' operator */
    AdData minTable[len][101];
    for(i=0;i<len;++i)
	for(j=0;j<101;++j)
	    minTable[i][j] = NO_DATA;

    minTable[0][digit[0]].adNum = 0;
    minTable[0][digit[0]].lastAdPos = INFINITE;

    int t_sum=0;
    int t_ad_num=0;
    for(i=1;i<len;++i)
    {
    	for(j=0;j<101;++j)
    	{
    	    if(INFINITE != minTable[i-1][j].adNum){
		/* add the number with a add operator before it */
		t_sum = j+digit[i];
		if(101 > t_sum){
		    t_ad_num = minTable[i-1][j].adNum + 1;
		    if(t_ad_num < minTable[i][t_sum].adNum){
			minTable[i][j+digit[i]].adNum = t_ad_num;
			minTable[i][j+digit[i]].lastAdPos = i-1;
		    }
		}
		
		/* add the number without adding any add operator */
		if(0 == minTable[i-1][j].adNum){
		    /* if there is no ad operator in previous series */
		    t_sum = j*10+digit[i];
		    if(101 > t_sum){
			t_ad_num = 0;
			minTable[i][t_sum].adNum = t_ad_num;
			minTable[i][t_sum].lastAdPos = INFINITE;;
		    }
		}else if(0 < minTable[i-1][j].adNum){
		    /* if there is ad operators in previous series */
		    /* caculate the last number */
		    int last_num = 0;
		    int k;
		    for(k=minTable[i-1][j].lastAdPos+1; k<i; ++k)
		    {
			last_num += digit[k] * pow(10,i-k-1);
		    }
		    t_sum = j + last_num*9 + digit[i];
		    /* printf("last_num == %d\n",last_num); */
		    /* printf("t_sum == %d\n",t_sum); */
		    if(101 > t_sum){
			t_ad_num = minTable[i-1][j].adNum;
			if(t_ad_num < minTable[i][t_sum].adNum){
			    minTable[i][t_sum].adNum = t_ad_num;
			    minTable[i][t_sum].lastAdPos = minTable[i-1][j].lastAdPos;
			}
		    }
    		}
    	    }
    	}
    }

    if(INFINITE != minTable[len-1][sum].adNum){
	ret = minTable[len-1][sum].adNum;
    }else{
	ret = -1;
    }

    /* for(j=0;j<len;++j) */
    /* { */
    /* 	printf("%d digit: %d\n",j,digit[j]); */
    /* 	for(i=0;i<101;++i) */
    /* 	{ */
    /* 	    if(INFINITE != minTable[j][i].adNum){ */
    /* 		printf("sum == %d, op_num == %d, last add pos == %d\n",i, */
    /* 		       minTable[j][i].adNum, */
    /* 		       minTable[j][i].lastAdPos); */
    /* 	    } */
    /* 	} */
    /* 	printf("---------------------\n"); */
    /* } */
    
    return ret;
}


int main(int argc,char ** argv)
{
    printf("QuickSums\n");

    int ret=0;
    int test_sum=0;
    
    char test_num_0[] = TEST_NUM_0;
    test_sum = TEST_SUM_0;
    ret = minSums(test_num_0,test_sum);
    printf("ret == %d\n",ret);

    char test_num_1[] = TEST_NUM_1;
    test_sum = TEST_SUM_1;
    ret = minSums(test_num_1,test_sum);
    printf("ret == %d\n",ret);

    char test_num_2[] = TEST_NUM_2;
    test_sum = TEST_SUM_2;
    ret = minSums(test_num_2,test_sum);
    printf("ret == %d\n",ret);

    char test_num_3[] = TEST_NUM_3;
    test_sum = TEST_SUM_3;
    ret = minSums(test_num_3,test_sum);
    printf("ret == %d\n",ret);

    char test_num_4[] = TEST_NUM_4;
    test_sum = TEST_SUM_4;
    ret = minSums(test_num_4,test_sum);
    printf("ret == %d\n",ret);

    char test_num_5[] = TEST_NUM_5;
    test_sum = TEST_SUM_5;
    ret = minSums(test_num_5,test_sum);
    printf("ret == %d\n",ret);
    
    return 0;
}
