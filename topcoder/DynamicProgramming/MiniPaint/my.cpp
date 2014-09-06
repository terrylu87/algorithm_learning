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
/* http://community.topcoder.com/stat?c=problem_statement&pm=1996&rd=4710 */

#include <string>
#include <iostream>
#include <string.h>
//#include <stdlib.h>

using namespace std;

/* test data */
// 0)	
const string TEST_MAP_0[] =\
{"BBBBBBBBBBBBBBB",	   \
 "WWWWWWWWWWWWWWW",	   \
 "WWWWWWWWWWWWWWW",	   \
 "WWWWWBBBBBWWWWW"};
const int MAX_STROKES_0 = 6;
// Returns: 0
// Exactly enough strokes to finish the job.

// 1)	
const string TEST_MAP_1[]={
"BBBBBBBBBBBBBBB",
"WWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWW",
"WWWWWBBBBBWWWWW"};
const int MAX_STROKES_1 = 4;
// Returns: 5
// One stroke for each row produces the least problem.

// 2)	
const string TEST_MAP_2[]={
"BBBBBBBBBBBBBBB",
"WWWWWWWWWWWWWWW",
"WWWWWWWWWWWWWWW",
"WWWWWBBBBBWWWWW"};
const int MAX_STROKES_2 = 0;
// Returns: 60
// Now the entire picture will be mispainted.

// 3)	
const string TEST_MAP_3[]={
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
"BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW"};
const int MAX_STROKES_3 = 100;
// Returns: 40
// This one needs a lot of strokes.

// 4)	
const string TEST_MAP_4[]={"B"};
const int MAX_STROKES_4 = 1;
// Returns: 0

typedef struct{
    int color;
    int length;
}Block;

const short W = 0;
const short B = 1;
const short U = -1;

void print_bolcks(void* _blocks,int row,int col)
{
    int i,j;
    Block (&blocks)[row][col] = *((Block (*)[row][col])_blocks);
    for(i=0;i<row;++i){
    	for(j=0;j<col;++j){
    	    if(0 == blocks[i][j].length) break;
    	    cout << "row: " << i << "  color: " << blocks[i][j].color << "  length: " << blocks[i][j].length << endl;
    	}
    	cout << "-----------------" << endl;
    }
}

int leastBad(const string picture[], int row, int maxStrokes)
{
    int i,j,k,l,m;
    int col = picture[0].size();

    Block blocks[row][col];
    memset(blocks,0,sizeof(Block)*row*col);

    int num_blocks[row];
    
    for(i=0;i<row;++i){
	char pre_color = '#';
	k=-1;
	for(j=0;j<col;++j){
	    if(picture[i][j] != pre_color){
		pre_color = picture[i][j];
		++k;
		if(picture[i][j] == 'B') blocks[i][k].color = B;
	    }
	    blocks[i][k].length++;
	}
	num_blocks[i] = k+1;
    }
    
    print_bolcks(blocks,row,col);
    // for(i=0;i<row;++i){
    // 	cout << "num_blocks : " << num_blocks[i] << endl;
    // }

    int remain[row][col];
    memset(remain,0,sizeof(int)*row*col);

    for(i=0;i<row;++i){
	// row_cache[strokes][stop_position][previous_color] = mispainted_area
	int row_cache[maxStrokes][num_blocks[i]][3];
	memset(row_cache,0,sizeof(int)*maxStrokes*num_blocks[i]*3);
	// caculate the mispainted area for specific given strokes
	for(j=0;j<num_blocks[i];++j){
	}
    }

    return 0;
}

#define TEST(DATA,maxStrokes) leastBad(DATA,sizeof(DATA)/sizeof(string),maxStrokes);

int main(int argc,char ** argv)
{
    cout << "MiniPaint" << endl;
    
    TEST(TEST_MAP_0,MAX_STROKES_0);
    // TEST(TEST_MAP_1,MAX_STROKES_1);
    // TEST(TEST_MAP_2,MAX_STROKES_2);
    // TEST(TEST_MAP_3,MAX_STROKES_3);
    // TEST(TEST_MAP_4,MAX_STROKES_4);
    
    return 0;
}
