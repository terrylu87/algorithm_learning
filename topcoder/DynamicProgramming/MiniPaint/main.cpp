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
//#include <stdlib.h>

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

// int[][][] cache = new int[3][50][51];
// int BIG = 3000;
// int stripScore(int[][] row, int[][][] cache, int start, int needed, int prev) {
//    if (needed > 0 && start >= row[0].length) return BIG;
//    if (needed == 0 || start >= row[0].length) return 0;
//    if (cache[prev][start][needed] != -1) return cache[prev][start][needed];
//    int best = BIG;
//    for (int i = 0; i < 3; i++) {
//       int newneeded = needed, adder = 0;
//       if (i == 0 || i == prev) newneeded--;
//       if (i == 0 || i!=row[1][start]) adder += row[0][start];
//       best = Math.min(best,stripScore(row,rowid,start+1,newneeded,i)+adder);
//    } return cache[prev][start][needed] = Math.min(BIG,best);
// }

// TODO pass value blocks
int stripScore(SpVecBlock blocks,  Cache &cache, int start, int needed, int prev)
{
    int num_blocks = blocks->size();
    int best = BIG;
    // Block (&blocks)[num_blocks] = *((Block (*)[num_blocks]) _blocks);
    if (needed > 0 && start >= num_blocks) return BIG;
    // TODO
    // if need == 0 , then the color must be the same as prev
    if (needed < 0 || start >= num_blocks) return 0;
    if (cache[prev][start][needed] != -1) return cache[prev][start][needed];
    // cout << "++++++++++ block size == " << num_blocks << endl;
    // for(int i = 0;i<num_blocks;++i) {
    // 	cout << "  i: " << i <<  "  color: " << (*blocks)[i]->color << "   length: "  << (*blocks)[i]->length ;
    // }
    // cout << "++++++++++" << endl;

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
    cout << "start: " << start << "  needed: " << needed << "  pre: " << prev << "  ret: "
	 << cache[prev][start][needed] << endl;
    return cache[prev][start][needed];
}

int leastBad(const string picture[], int row, int maxStrokes)
{
    int i,j,k,l,m,n;
    int col = picture[0].size();
    shared_ptr<int> a;
    // vector<shared_ptr<vector<Block> > > vec_blocks;
    vector<SpVecBlock> vec_blocks;

    for(i=0;i<row;++i){
    	char pre_color = '#';
	// zllu
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
    // return 0;
    cout << "nice" << endl;
    print_vec_bolcks(vec_blocks);
    // for(i=0;i<row;++i){
    // 	cout << "num_blocks : " << num_blocks[i] << endl;
    // }

    int remain[row][col];
    memset(remain,0,sizeof(int)*row*col);

    Cache cache;

    int r = 3;
    for(i=0;i<maxStrokes;++i)
    {
        for(l=0;l<3;++l) for(m=0;m<50;++m) for(n=0;n<51;++n) cache[l][m][n] = -1;
        for(j=0;j<=maxStrokes;++j){
            // remain[r][i] = stripScore(vec_blocks[r],cache,0,j,0);
        }
    }
    
    // test
    SpBlock b1(new Block);
    SpBlock b2(new Block);
    b1->color=2;
    b1->length=5;
    b2->color=1;
    b2->length=5;
    SpVecBlock vb(new vector<SpBlock>);
    vb->push_back(b1);
    vb->push_back(b2);
    for(l=0;l<3;++l) for(m=0;m<50;++m) for(n=0;n<51;++n) cache[l][m][n] = -1;
    for(j=0;j<=maxStrokes;++j){
    	int score = stripScore(vb,cache,0,j,0);
    }
    // test
    
    // caculate the mispainted area for specific given strokes
    // for(i=0;i<row;++i){
    // 	for(l=0;l<3;++l) for(m=0;m<50;++m) for(n=0;n<51;++n) cache[l][m][n] = -1;
    // 	for(j=0;j<=maxStrokes;++j){
    // 	    // TODO
    // 	    remain[i][j] = stripScore(vec_blocks[i],cache,0,j,0);
    // 	    // remain[i][j] = col - stripScore(vec_blocks[i],cache,0,j,0);
    // 	}
    // }

    // for(i=0;i<row;++i){
    // 	for(j=0;j<col;++j){
    // 	    cout << "row: " << i << " given_strokes: " << j << " remains: " << remain[i][j] << endl;
    // 	    if(0 == remain[i][j]) continue;
    // 	}
    // 	cout << "---------------------" << endl;
    // }

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
