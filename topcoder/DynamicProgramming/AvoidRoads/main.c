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
/* http://community.topcoder.com/stat?c=problem_statement&pm=1889&rd=4709 */

/* test data */
/* 0)	 */
#define WIDTH_0 6
#define HEIGHT_0 6
#define BAD_0 {"0 0 0 1","6 6 5 6"}
/* Returns: 252 */
/* Example from above. */

/* 1)	 */
#define WIDTH_1 1
#define HEIGHT_1 1
#define BAD_1 {}
/* Returns: 2 */
/* Four blocks aranged in a square. Only 2 paths allowed. */

/* 2)	 */
#define WIDTH_2 35
#define HEIGHT_2 31
#define BAD_2 {}
/* Returns: 6406484391866534976 */
/* Big number. */

/* 3)	 */
#define WIDTH_3 2
#define HEIGHT_3 2
#define BAD_3 {"0 0 1 0", "1 2 2 2", "1 1 2 1"}
/* Returns: 0 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_UP 0x08
#define BLOCK_DOWN 0x04
#define BLOCK_LEFT 0x02
#define BLOCK_RIGHT 0x01

void print_lmap(unsigned long long *map,int width,int height)
{
    int i;
    int j;
    for(i=height;i>=0;--i)
    {
	for(j=0;j<width+1;++j)
	{
	    printf("%lld ",*(map+j+i*(width+1)));
	}
	printf("\n");
    }
}

void print_map(unsigned char *map,int width,int height)
{
    int i;
    int j;
    for(i=height;i>=0;--i)
    {
	for(j=0;j<width+1;++j)
	{
	    printf("%d ",*(map+j+i*(width+1)));
	}
	printf("\n");
    }
}

long long numWays(int width, int height, char *bad[], int bad_size)
{
    unsigned char block_map[height+1][width+1];
    memset(block_map,0,sizeof(unsigned char)*(height+1)*(width+1));
    
    int i=0,j=0;
    for(i=0;i<bad_size;++i)
    {
	int x1=0,y1=0,x2=0,y2=0;
	sscanf(bad[i],"%d%d%d%d",&x1,&y1,&x2,&y2);
	/* printf("%d %d %d %d\n",x1,y1,x2,y2); */
	if(1 == (x2-x1)){
	    block_map[y1][x1] |= BLOCK_RIGHT;
	    block_map[y2][x2] |= BLOCK_LEFT;
	}else if(-1 == (x2-x1)){
	    block_map[y1][x1] |= BLOCK_LEFT;
	    block_map[y2][x2] |= BLOCK_RIGHT;
	}else if(1 == (y2-y1)){
	    block_map[y1][x1] |= BLOCK_UP;
	    block_map[y2][x2] |= BLOCK_DOWN;
	}else if(-1 == (y2-y1)){
	    block_map[y1][x1] |= BLOCK_DOWN;
	    block_map[y2][x2] |= BLOCK_UP;
	}
    }
    /* print_map(block_map,width,height); */
    
    long long S[height+1][width+1];
    for(i=0;i<=height;++i)
    {
    	for(j=0;j<=width;++j)
    	{
    	    S[i][j] = 0;
	    if(i==0 && j==0){
	    }else if(i==0 && j==1){
		if(!(block_map[i][j] & BLOCK_LEFT)){
    		    S[i][j] = 1;
    		}
    	    }else if(i==1 && j==0){
    		if(!(block_map[i][j] & BLOCK_DOWN)){
    		    S[i][j] = 1;
    		}
    	    }else{
    		if(i>0 && !(block_map[i][j] & BLOCK_DOWN)){
    		    S[i][j] += S[i-1][j];
    		}
    		if(j>0 && !(block_map[i][j] & BLOCK_LEFT)){
    		    S[i][j] += S[i][j-1];
    		}
    	    }
    	}
    }
    
    return S[height][width];
}

int main(int argc,char ** argv)
{
    printf("AvoidRoads\n");

    int width=0,height=0;
    int bad_size=0;
    long long ret=0;
    
    width = WIDTH_0;
    height = HEIGHT_0;
    char *bad_0[]  = BAD_0;
    bad_size = sizeof(bad_0)/sizeof(char*);
    ret = numWays(width,height,bad_0,bad_size);
    printf("ret == %llu\n",ret);

    width = WIDTH_1;
    height = HEIGHT_1;
    char *bad_1[] = BAD_1;
    bad_size = sizeof(bad_1)/sizeof(char*);
    ret = numWays(width,height,bad_1,bad_size);
    printf("ret == %lld\n",ret);

    width = WIDTH_2;
    height = HEIGHT_2;
    char *bad_2[] = BAD_2;
    bad_size = sizeof(bad_2)/sizeof(char*);
    ret = numWays(width,height,bad_2,bad_size);
    printf("ret == %llu\n",ret);

    width = WIDTH_3;
    height = HEIGHT_3;
    char *bad_3[] = BAD_3;
    bad_size = sizeof(bad_3)/sizeof(char*);
    ret = numWays(width,height,bad_3,bad_size);
    printf("ret == %lld\n",ret);
    
    
    return 0;
}
