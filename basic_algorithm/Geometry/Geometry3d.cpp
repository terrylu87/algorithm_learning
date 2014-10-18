/*
 * =====================================================================================
 *
 *       Filename:  Geometry3d.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Sat Oct 18 15:24:00 2014
 *
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TerryLu, terrylu87@gmail.com
 *        Company:  Terry's working house
 *
 * =====================================================================================
 */
#include "Geometry3d.h"

// begin of Vector3d definition
Vector3d::Vector3d(double _x,double _y,double _z)
{
    x = _x;
    y = _y;
    z = _z;
}

Vector3d::~Vector3d()
{
    ;
}

Vector3d Vector3d::operator+(const Vector3d& p)
{
    Vector3d ret;
    ret.x = x + p.x;
    ret.y = y + p.y;
    ret.z = z + p.z;
    return ret;
}

Vector3d Vector3d::operator-(const Vector3d& p)
{
    Vector3d ret;
    ret.x = x - p.x;
    ret.y = y - p.y;
    ret.z = z - p.z;
    return ret;
}

double Vector3d::operator*(const Vector3d& p)
{
    return (x*p.x + y*p.y + z*p.z);
}

Vector3d Vector3d::operator^(const Vector3d& p)
{
    Vector3d ret;
    ret.x = y*p.z - z*p.y;
    ret.y = z*p.x - x*p.z;
    ret.z = x*p.y - y*p.x;
    return ret;
}

std::ostream& operator<<(std::ostream& os, const Vector3d& v)
{
    return os << "(" << v.x << "," << v.y << "," << v.z << ")";
}
// end of Vector3d definition