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
#include "Geometry.h"
//#include <stdlib.h>

using namespace std;

int main(int argc,char ** argv)
{
    Vector2d a(1,2),b(3,4);
    Vector2d c(0,0);
    // c = a+b;
    // c = a^b;
    cout << c << endl;

    return 0;
}