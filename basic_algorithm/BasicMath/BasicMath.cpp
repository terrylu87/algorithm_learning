/*
 * =====================================================================================
 *
 *       Filename:  BasicMath.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Mon Oct 13 20:28:38 2014
 *
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TerryLu, terrylu87@gmail.com
 *        Company:  Terry's working house
 *
 * =====================================================================================
 */
#include "BasicMath.h"

#include <cmath>

using namespace std;

bool isPrime (int n)
{
   if (n<=1) return false;
   if (n==2) return true;
   if (n%2==0) return false;
   int m=sqrt(n);

   for (int i=3; i<=m; i+=2)
      if (n%i==0)
         return false;

   return true;
}

//assume that a and b cannot both be 0
int GCD(int a, int b)
{
   if (b==0) return a;
   return GCD(b,a%b);
}

int LCM(int a, int b)
{
   return b*a/GCD(a,b);
}

int toDecimal(int n, int b)
{
   int result=0;
   int multiplier=1;

   while(n>0)
   {
      result+=n%10*multiplier;
      multiplier*=b;
      n/=10;
   }

   return result;
}

int fromDecimal(int n, int b)
{
   int result=0;
   int multiplier=1;

   while(n>0)
   {
      result+=n%b*multiplier;
      multiplier*=10;
      n/=b;
   }

   return result;
}

string fromDecimal2(int n, int b)
{
   string chars="0123456789ABCDEFGHIJ";
   string result="";

   while(n>0)
   {
      result=chars.at(n%b) + result;
      n/=b;
   }

   return result;
}