/*
 * =====================================================================================
 *
 *       Filename:  answer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014-08-19 13:52:03
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  TerryLu, terrylu87@gmail.com
 *        Company:  Delphi CTC
 *
 * =====================================================================================
 */

// View StarAdventure   Problem Statement
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <iostream>
#include <math.h>
#include <queue>
#include <iterator>
#include <sstream>
#include <stdio.h>
 
using namespace std;
 
#define fi(a, b) for(int i=((int)(a)); i < ((int)(b)); i++)
#define fie(a, b) for(int i=((int)(a)); i <= ((int)(b)); i++)
#define fj(a, b) for(int j=((int)(a)); j < ((int)(b)); j++)
#define fje(a, b) for(int j=((int)(a)); j <= ((int)(b)); j++)
#define fk(a, b) for(int k=((int)(a)); k < ((int)(b)); k++)
#define fl(a, b) for(int l=((int)(a)); l < ((int)(b)); l++)
#define di(a) for(int i=(int)((a)-1); i>=0; i--)
#define dj(a) for(int j=(int)((a)-1); j>=0; j--)
#define die(a) for(int i=(int)(a); i>=0; i--)
#define dje(a) for(int j=(int)(a); j>=0; j--)
#define fdi(a, b) for(int i=((int)(a)); i > ((int)(b)); i--)
#define fdj(a, b) for(int j=((int)(a)); j > ((int)(b)); j--)
#define fdk(a, b) for(int k=((int)(a)); k > ((int)(b)); k--)
#define fdl(a, b) for(int l=((int)(a)); l > ((int)(b)); l--)
#define ri(b) for(int i=0; i < ((int)(b)); i++)
#define rie(b) for(int i=0; i <= ((int)(b)); i++)
#define rj(b) for(int j=0; j < ((int)(b)); j++)
#define rje(b) for(int j=0; j <= ((int)(b)); j++)
#define rk(b) for(int k=0; k < ((int)(b)); k++)
#define rke(b) for(int k=0; k < ((int)(b)); k++)
#define rl(b) for(int l=0; l < ((int)(b)); l++)
 
#define itadj for(int adx=-1; adx<=1; adx++) for(int ady=-1; ady<=1; ady++)
#define chkadj(i, j, n, m) ((i)>=0&&(j)>=0&&(i)<n&&(j)<m)
 
#define fe(v,it) for(__typeof(v.begin()) it=v.begin(); it != v.end(); it++)
 
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef long long ll;
typedef unsigned long long u64;
typedef string str;
typedef double dbl;
 
#define bz(a) memset(a,0,sizeof(a))
#define sq(x) ((x)*(x))
 
typedef vector< i32 > vi;
typedef vector< str > vs;
typedef vector< i64 > vl;
typedef vector< vi  > vvi;
typedef vector< vs  > vvs;
typedef vector< dbl > vd;
typedef vector< vd  > vvd;
 
typedef set< i32 > si;
typedef set< str  > ss;
 
typedef vi::iterator  itri;
typedef vvi::iterator itrvi;
typedef vs::iterator  itrs;
typedef vvs::iterator itrvs;
typedef vd::iterator  itrd;
typedef vvd::iterator itrvd;
 
#define ffof   find_first_of
#define ffnof  find_first_not_of
 
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define ABS(a)   MAX((a),-(a))
#define DIST(a,b) ABS((a)-(b))
 
#define vp(v,a)  (v).push_back(a)
#define vpb(v,a) (v).push_back(a)
#define vpf(v,a) (v).push_front(a)
#define vpob(v) (v).pop_back()
#define vpof(v) (v).pop_front()
 
#define va(v) (v).begin(), (v).end()
#define vf(v,a) find(va(v),(a))
#define ve(v,a) (vf(v,a)!=(v).end())
#define vins(v,a) do { if (!ve(v,a)) vpb(v, a); } while(0)
#define vind(v,a) (ve(v,a)?(vf(v,a)-v.begin()):-1)
#define vdel(v,a) v.erase(remove(va(v),a),v.end())
 
inline i64 gcd(i64 a, i64 b) { if (b==0) return a; return gcd(b, a%b); }
inline i64 lcm(i64 a, i64 b) { return (a*b)/gcd(a,b);                  }
 
#define sz size()
 
#define mp(x, y) make_pair(x, y)
#define mt(x, y, z) mp(mp(x,y),z)
 
#define pfst(p) (p).first
#define pscd(p) (p).second
 
#define tfst(t) (t).first.first
#define tscd(t) (t).first.second
#define tthd(t) (t).second
 
typedef pair<int, int> pii;
typedef pair<int, str> pis;
typedef pair<str, int> psi;
typedef pair<str, str> pss;
 
typedef pair< pii, int > tii;
typedef pair< pss, str > tss;
 
#define pq priority_queue
 
#define dbg_vint(v) do { copy(va(v),ostream_iterator<int>(cout,"\t")); cout << endl; } while(0)
#define dbg_vstr(v) do { copy(va(v),ostream_iterator<str>(cout,"\n")); cout << endl; } while(0)
#define dbg_vdbl(v) do { copy(va(v),ostream_iterator<dbl>(cout,"\t")); cout << endl; } while(0)
 
int mem[102][51][51][51];
 
vs l;
 
int doit(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (x1>=l[0].sz||y1>=l.sz||x2>=l[0].sz||y2>=l.sz||x3>=l[0].sz||y3>=l.sz) return 0;
    int m=x1+y1;
    if (mem[m][x1][x2][x3]) return mem[m][x1][x2][x3]-1;
  
    int ret=l[y1][x1]-'0';
    if (mp(x1,y1)!=mp(x2,y2)) ret += l[y2][x2]-'0';
    if (mp(x1,y1)!=mp(x3,y3)&&mp(x2,y2)!=mp(x3,y3)) ret += l[y3][x3]-'0';
  
    int add=0;
    ri(2) rj(2) rk(2)
	    add >?= doit((i?x1+1:x1),(i?y1:y1+1),(j?x2+1:x2),(j?y2:y2+1),(k?x3+1:x3),(k?y3:y3+1));
  
    ret += add;
    mem[m][x1][x2][x3] = ret + 1;
  
    return ret;
}
 
class StarAdventure {
  public:
    int mostStars(vector <string> level) {
    
	// BEGIN CUT HERE
	static bool s_FirstTime = true; if (s_FirstTime) { s_FirstTime = false; run_test(-1); }
	// END CUT HERE
	bz(mem);
 
	l=level;
 
	return doit(0,0,0,0,0,0);
    
    }
  
    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"01",
					  "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, mostStars(Arg0)); }
    void test_case_1() { string Arr0[] = {"0999999999"
					  ,"9999999999"
					  ,"9999999999"
					  ,"9999999999"
					  ,"9999999999"
					  ,"9999999999"
					  ,"9999999999"
					  ,"9999999999"
					  ,"9999999999"
					  ,"9999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 450; verify_case(1, Arg1, mostStars(Arg0)); }
    void test_case_2() { string Arr0[] = {"012"
					  ,"012"
					  ,"012"
					  ,"012"
					  ,"012"
					  ,"012"
					  ,"012"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(2, Arg1, mostStars(Arg0)); }
    void test_case_3() { string Arr0[] = {"0123456789",
					  "1123456789",
					  "2223456789",
					  "3333456789",
					  "4444456789",
					  "5555556789",
					  "6666666789",
					  "7777777789",
					  "8888888889",
					  "9999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 335; verify_case(3, Arg1, mostStars(Arg0)); }
 
    // END CUT HERE
 
};
 
// Powered by PopsEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

