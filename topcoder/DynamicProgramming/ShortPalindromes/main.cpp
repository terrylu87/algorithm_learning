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
/* http://community.topcoder.com/stat?c=problem_statement&pm=1861&rd=4630 */

/* test data */
// 0)	
#define TEST_STR_0 "RACE"
// Returns: "ECARACE"
// To make "RACE" into a palindrome, we must add at least three letters. However, there are eight ways to do this by adding exactly three letters:
//     "ECARACE"  "ECRARCE"  "ERACARE"  "ERCACRE"
//     "RACECAR"  "RAECEAR"  "REACAER"  "RECACER"
// Of these alternatives, "ECARACE" is the lexicographically earliest.

// 1)	
#define TEST_STR_1 "TOPCODER"
// Returns: "REDTOCPCOTDER"

// 2)	
#define TEST_STR_2 "Q"
// Returns: "Q"

// 3)	
#define TEST_STR_3 "MADAMIMADAM"
// Returns: "MADAMIMADAM"

// 4)	
#define TEST_STR_4 "ALRCAGOEUAOEURGCOEUOOIGFA"
// Returns: "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA"

#define TEST_STR_5 "GRAPE"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

// string r_shortest(string base) {
//     string bests[26][26];
//     int len = base.length();
//     if ( len <= 1 ) return base;
//     for ( int i = 0; i < len; ++i ) bests[i][1] = base[i];
 
//     for ( int termlen = 2; termlen <= len; ++termlen ) for ( int i = 0; i <= len-termlen; ++i ) {
//       string term(base, i, termlen);
//       char first = term[0], last = term[termlen-1];
//       if ( first == last ) bests[i][termlen] = first+bests[i+1][termlen-2]+last;
//       else {
//         string s1 = first+bests[i+1][termlen-1]+first;
//         string s2 = last+bests[i][termlen-1]+last;
//         string& res = bests[i][termlen];
//         if ( s1.length() < s2.length() ) res = s1;
//         else if ( s1.length() > s2.length() ) res = s2;
//         else if ( s1 < s2 ) res = s1;
//         else res = s2;
//       }
//     }
 
//     return bests[0][len];
// }

string shortest(const string& base)
{
    int size = base.size();
    string palindrome[size+1][size+1];

    int i,j;
    for(i=0;i<base.size();++i)
	palindrome[i][1] = base[i];

    for(int substrlen=2; substrlen<=size; ++substrlen)
    {
	for(int start_pos=0; start_pos<=size-substrlen; ++start_pos)
	{
	    string substr = base.substr(start_pos,substrlen);
	    char first = substr[0];
	    char last = substr[substrlen-1];
	    if(first == last){
		palindrome[start_pos][substrlen] = first + palindrome[start_pos+1][substrlen-2] + last;
	    }else{
		string& target_str = palindrome[start_pos][substrlen];
		string a = last + palindrome[start_pos][substrlen-1] + last;
		string b = first + palindrome[start_pos+1][substrlen-1] + first;
		if(a.size() < b.size()){
		    target_str = a;
		}else if(a.size() > b.size()){
		    target_str = b;
		}else{
		    if(a<b){
			target_str = a;
		    }else{
			target_str = b;
		    }
		}
	    }
	}
    }
    return palindrome[0][size];
}

int main(int argc,char ** argv)
{
    cout << "ShortPalindromes" << endl;
    const char* test_data[] = {TEST_STR_0,TEST_STR_1,TEST_STR_2,TEST_STR_3,TEST_STR_4,TEST_STR_5};
    // const char* test_data[] = {TEST_STR_1};
    vector<string> v_test_str;
    for(int i=0; i<(sizeof(test_data)/sizeof(char*)); ++i)
	v_test_str.push_back(test_data[i]);

    string ret;
    vector<string>::const_iterator it;
    // for(it=v_test_str.begin(); it!=v_test_str.end(); ++it)
    // {
    // 	cout << *it << endl;
    // }

    for(it=v_test_str.begin(); it!=v_test_str.end(); ++it)
    {
    	// ret = shortest(*it);
	ret = shortest(*it);
    	cout << "ret == " << ret << endl;
    }

    return 0;
}


