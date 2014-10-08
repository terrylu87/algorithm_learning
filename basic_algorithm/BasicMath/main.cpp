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

/* test data */

#include <iostream>
//#include <stdlib.h>

using namespace std;

public boolean isPrime (int n)
{
   if (n<=1) return false;
   if (n==2) return true;
   if (n%2==0) return false;
   int m=Math.sqrt(n);

   for (int i=3; i<=m; i+=2)
      if (n%i==0)
         return false;

   return true;
}

int main(int argc,char ** argv)
{
    cout << "hello haker" << endl;

    return 0;
}
