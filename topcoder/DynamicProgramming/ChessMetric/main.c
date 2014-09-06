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
/* http://community.topcoder.com/stat?c=problem_statement&pm=1592&rd=4482 */

/* test data */
/* 0) */
#define SIZE_0 3
#define START_0 {0,0}
#define FINISH_0 {1,0}
#define MOVES_0 1
/* Returns: 1 */
/* Only 1 way to get to an adjacent square in 1 move */

/* 1)	 */
#define SIZE_1 3
#define START_1 {0,0}
#define FINISH_1 {1,2}
#define MOVES_1 1
/* Returns: 1 */
/* A single L-shaped move is the only way */

/* 2)	 */
#define SIZE_2 3
#define START_2 {0,0}
#define FINISH_2 {2,2}
#define MOVES_2 1
/* Returns: 0 */
/* Too far for a single move */

/* 3)	 */
#define SIZE_3 3
#define START_3 {0,0}
#define FINISH_3 {0,0}
#define MOVES_3 2
/* Returns: 5 */
/* Must count all the ways of leaving and then returning to the corner */

/* 4)	 */
#define SIZE_4 100
#define START_4 {0,0}
#define FINISH_4 {0,99}
#define MOVES_4 50
/* Returns: 243097320072600 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int (move[])[2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} \
			  ,{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };

long long howMany(int size,int start[2], int end[2], int moves)
{
    /* printf("%d  %d,%d  %d,%d  %d\n",size,start[0],start[1],end[0],end[1],moves); */
    long long ret = 0;

    long long S[moves+1][size][size];
    memset(S,0,sizeof(long long)*size*size*(moves+1));

    int sx=start[0],sy=start[1];
    int i,j,k;

    for(i=0;i<16;++i)
    {
	int tx = sx+move[i][0];
	int ty = sy+move[i][1];
	if(tx>=0 && tx<size && ty>=0 && ty<size){
	    S[1][ty][tx] = 1;
	}
    }

    for(i=2;i<=moves;++i)
    {
	for(j=0;j<size;++j)
	{
	    for(k=0;k<size;++k)
	    {
		if(S[i-1][j][k] != 0){
		    int l;
		    for(l=0;l<16;++l)
		    {
			int tx = k+move[l][0];
			int ty = j+move[l][1];
			if(tx>=0 && tx<size && ty>=0 && ty<size){
			    S[i][ty][tx] += S[i-1][j][k];
			}
		    }
		}
	    }
	}
    }

    ret = S[moves][end[0]][end[1]];
    return ret;
}

int main(int argc,char ** argv)
{
    printf("ChessMetric\n");

    int size=0;
    int moves = 0;
    long long ret=0;

    size = SIZE_0;
    int start_0[] = START_0;
    int finish_0[] = FINISH_0;
    moves = MOVES_0;
    ret = howMany(size,start_0,finish_0,moves);
    printf("ret == %llu\n",ret);
    
    size = SIZE_1;
    int start_1[] = START_1;
    int finish_1[] = FINISH_1;
    moves = MOVES_1;
    ret = howMany(size,start_1,finish_1,moves);
    printf("ret == %llu\n",ret);
    
    size = SIZE_2;
    int start_2[] = START_2;
    int finish_2[] = FINISH_2;
    moves = MOVES_2;
    ret = howMany(size,start_2,finish_2,moves);
    printf("ret == %llu\n",ret);

    size = SIZE_3;
    int start_3[] = START_3;
    int finish_3[] = FINISH_3;
    moves = MOVES_3;
    ret = howMany(size,start_3,finish_3,moves);
    printf("ret == %llu\n",ret);

    size = SIZE_4;
    int start_4[] = START_4;
    int finish_4[] = FINISH_4;
    moves = MOVES_4;
    ret = howMany(size,start_4,finish_4,moves);
    printf("ret == %llu\n",ret);

    return 0;
}
