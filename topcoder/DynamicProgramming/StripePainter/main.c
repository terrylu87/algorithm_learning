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
/* http://community.topcoder.com/stat?c=problem_statement&pm=1215&rd=4555 */

/* test data */
/* 0)	 */
#define TEST_STR_0 "RGBGR"
/* #define TEST_STR_0 "GBG" */
/* Returns: 3 */
/* Example from introduction. */

/* 1)	 */
#define TEST_STR_1 "RGRG"
/* Returns: 3 */
/* This example cannot be done in two strokes, even though there are only two colors. Suppose you tried to paint both red stripes in one stroke, followed by both green stripes in one stroke. Then the green stroke would cover up the second red stripe. If you tried to paint both green stripes first, followed the red stripes, then the red stroke would cover up the first green stripe. */

/* 2)	 */
#define TEST_STR_2 "ABACADA"
/* Returns: 4 */
/* One long stroke in color 'A', followed by one stroke each in colors 'B', 'C', and 'D'. */

/* 3)	 */
#define TEST_STR_3 "AABBCCDDCCBBAABBCCDD"
/* Returns: 7 */

/* 4)	 */
#define TEST_STR_4 "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD"
/* Returns: 26 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getSimpleStr(char* sstr,char* stripes,int size)
{
    char preivous_char = '#';
    int i=0;
    int j=0;
    for(i=0;i<size;++i)
    {
	if(*(stripes+i) != preivous_char){
	    preivous_char = *(stripes+i);
	    *(sstr+j) = preivous_char;
	    ++j;
	}
    }
}

int getMinStrokes(char* str,int size)
{
    int minStrokes = 100;
    char sstr[size+1];
    memset(sstr,0,size+1);
    strncpy(sstr,str,size);

    if(1 == strlen(sstr)){
	return 1;
    }
    /* printf("start calculate sstr : %s, size == %d\n",sstr,size); */

    /* find the characters which shows most often. */
    /* Preserve their index in array divideCharIndex */
    int times[24];
    memset(times,0,sizeof(times));
    int i=0;
    for(i=0;i<strlen(sstr);++i)
    {
	times[*(sstr+i)-'A'] += 1;
    }

    int maxTime=0;
    int divideCharNum=0;
    for(i=0;i<24;++i)
    {
	if(maxTime < times[i]){
	    maxTime = times[i];
	    divideCharNum = 1;
	}else if(maxTime == times[i]){
	    ++divideCharNum;
	}
    }
    int divideCharIndex[divideCharNum];
    int j=0;
    for(i=0;i<24;++i)
    {
	if(maxTime == times[i]){
	    divideCharIndex[j] = i;
	    ++j;
	}
    }

    /* for every dividing character. Calculate the min strokes of every subsequence */
    for(i=0;i<divideCharNum;++i)
    {
	char divideChar = divideCharIndex[i] + 'A';
	/* printf("divideChar : %c\n",divideChar); */
	int startPos = -1;
	int strokes = 0;
	for(j=0;j<size;++j)
	{
	    if(divideChar != *(sstr+j)){
		if(-1 == startPos){
		    startPos = j;
		}
	    }else{
		if(-1 != startPos){
		    strokes += getMinStrokes(sstr+startPos,j-startPos);
		    startPos=-1;
		}
	    }
	}
	
	if(-1 != startPos){
	    strokes += getMinStrokes(sstr+startPos,size-startPos);
	}
	
	if(strokes < minStrokes){
	    minStrokes = strokes;
	}
	minStrokes++;
    }

    return minStrokes;
}

int minStrokes(char* stripes,int size)
{
    int ret = -1;
    char sstr[size];
    memset(sstr,0,sizeof(sstr));
    /* printf("stripes : %s\n",stripes); */
    getSimpleStr(sstr,stripes,size);
    /* printf("sstr : %s\n",sstr); */

    ret = getMinStrokes(sstr,strlen(sstr));

    return ret;
}

int main(int argc,char ** argv)
{
    printf("StripePainter\n");

    int ret=0;
    
    char test_str_0[] = TEST_STR_0;
    ret = minStrokes(test_str_0,sizeof(test_str_0)/sizeof(char));
    printf("ret == %d\n",ret);

    char test_str_1[] = TEST_STR_1;
    ret = minStrokes(test_str_1,sizeof(test_str_1)/sizeof(char));
    printf("ret == %d\n",ret);

    char test_str_2[] = TEST_STR_2;
    ret = minStrokes(test_str_2,sizeof(test_str_2)/sizeof(char));
    printf("ret == %d\n",ret);
    
    char test_str_3[] = TEST_STR_3;
    ret = minStrokes(test_str_3,sizeof(test_str_3)/sizeof(char));
    printf("ret == %d\n",ret);

    char test_str_4[] = TEST_STR_4;
    ret = minStrokes(test_str_4,sizeof(test_str_4)/sizeof(char));
    printf("ret == %d\n",ret);

    return 0;
}
