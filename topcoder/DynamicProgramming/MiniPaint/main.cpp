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
#include <vector>
#include <tr1/memory>
#include <stdlib.h>

using namespace std;
using namespace tr1;
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

const short U = 0;
const short W = 1;
const short B = 2;


const int BIG = 3000;

typedef shared_ptr<Block > SpBlock;
typedef shared_ptr<vector<SpBlock> > SpVecBlock;

void print_vec_bolcks(vector<SpVecBlock> &vec_blocks)
{
    vector<SpVecBlock>::const_iterator it_vv;
    vector<SpBlock>::const_iterator it_v;
    int i=0;
    for(it_vv=vec_blocks.begin(); it_vv!=vec_blocks.end(); ++it_vv){
    	for(it_v=(*it_vv)->begin(); it_v!=(*it_vv)->end(); ++it_v){
    	    cout << "row: " << i << "  color: " << (*it_v)->color << "  length: " << (*it_v)->length << endl;
    	}
    	cout << "-----------------" << endl;
    	++i;
    }
}
typedef int Cache[3][50][51];

int stripScore(SpVecBlock blocks,  Cache &cache, int start, int needed, int prev)
{
    int num_blocks = blocks->size();
    int best = BIG;
    if (needed > 0 && start >= num_blocks) return BIG;
    // if need == 0 , then the color must be the same as prev
    if (needed < 0 || start >= num_blocks) return 0;
    if (cache[prev][start][needed] != -1) return cache[prev][start][needed];

    if(start == (num_blocks-1)){
        if(0 == needed){
            if(prev != (*blocks)[start]->color) cache[prev][start][0] = (*blocks)[start]->length;
            else cache[prev][start][0] = 0;
        }else{
            cache[prev][start][needed] = 0;
        }
    }else{
        if(needed == 0){
            int adder = 0;
            if (prev == 0 || prev != (*blocks)[start]->color) adder += (*blocks)[start]->length;
            int score = stripScore(blocks,cache,start+1,0,prev)+adder;
            best = best < score ? best : score;
            cache[prev][start][needed] = best;
        }else{
            for (int i = 0; i < 3; i++) {
                // for each color used in this block
                int newneeded = needed, adder = 0;
                if (i != 0 && i != prev)  newneeded--;
                if (i == 0 || i != (*blocks)[start]->color) adder += (*blocks)[start]->length;
                int score = stripScore(blocks,cache,start+1,newneeded,i)+adder;
                best = best < score ? best : score;
            }
        }
        cache[prev][start][needed] = BIG < best ? BIG : best;
    }
    // cout << "start: " << start << "  needed: " << needed << "  pre: " << prev << "  ret: "
	 // << cache[prev][start][needed] << endl;
    return cache[prev][start][needed];
}

int leastBad(const string picture[], int row, const int maxStrokes)
{
    int i,j,k,l,m,n;
    int col = picture[0].size();
    shared_ptr<int> a;
    vector<SpVecBlock> vec_blocks;

    for(i=0;i<row;++i){
    	char pre_color = '#';
    	SpVecBlock blocks(new vector<SpBlock>());
    	for(j=0;j<col;++j){
    	    if(picture[i][j] != pre_color){
    		pre_color = picture[i][j];
    		SpBlock block(new Block);
            block->length = 0;
    		if(picture[i][j] == 'B') block->color = B;
    		else if(picture[i][j] == 'W') block->color = W;
    		blocks->push_back(block);
    	    }
    	    blocks->at(blocks->size()-1)->length++;
    	}
    	vec_blocks.push_back(blocks);
    }

    int remain[row][maxStrokes+1];
    memset(remain,0,sizeof(int)*row*(maxStrokes+1));

    Cache cache;

    for(int r = 0; r < row; ++r){
        for(l=0;l<3;++l) for(m=0;m<50;++m) for(n=0;n<51;++n) cache[l][m][n] = -1;
        for(j=0;j<=maxStrokes;++j){
            remain[r][j] = stripScore(vec_blocks[r],cache,0,j,0);
        }
    }

    // zllu
    // calculate the score for the whole picture.
    int Scores[row][maxStrokes+1];
    for(i=0;i<=maxStrokes;++i){
        Scores[0][i] = remain[0][i];
    }
    for(i=1;i<row;++i){
        // for each row
        for(j=0;j<=maxStrokes;++j){
            // for every possible strokes that can be taken for all rows including i row.
            int score = BIG;
            for(k=0;k<=j;++k){
                // for every possible strokes taken by i row
                // calculate the score
                int tmp_score = remain[i][k] + Scores[i-1][j-k];
                score = score < tmp_score ? score : tmp_score;
            }
            Scores[i][j] = score;
        }
    }
    cout << "------" << Scores[row-1][maxStrokes] << endl;

    return Scores[row-1][maxStrokes];
}

#define TEST(DATA,maxStrokes) leastBad(DATA,sizeof(DATA)/sizeof(string),maxStrokes);

int main(int argc,char ** argv)
{
    cout << "MiniPaint" << endl;

    TEST(TEST_MAP_0,MAX_STROKES_0);
    TEST(TEST_MAP_1,MAX_STROKES_1);
    TEST(TEST_MAP_2,MAX_STROKES_2);
    TEST(TEST_MAP_3,MAX_STROKES_3);
    TEST(TEST_MAP_4,MAX_STROKES_4);

    return 0;
}
