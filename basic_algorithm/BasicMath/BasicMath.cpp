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