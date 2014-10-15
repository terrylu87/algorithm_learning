/*
 * =====================================================================================
 *
 *       Filename:  BasicMath.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Mon Oct 13 20:27:08 2014
 *
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TerryLu, terrylu87@gmail.com
 *        Company:  Terry's working house
 *
 * =====================================================================================
 */

#ifndef _BASICMATH_H_
#define _BASICMATH_H_

#include <string>

bool isPrime (int n);

int GCD(int a, int b);

int LCM(int a, int b);

int toDecimal(int n, int b);

int fromDecimal(int n, int b);

std::string fromDecimal2(int n, int b);

#endif /* _BASICMATH_H_ */
