/*
 * =====================================================================================
 *
 *       Filename:  Geometry.cpp
 *
 *    Description:  Geometric algorithms using in topcoder. Because topcoder does not allow Boost. I have to implement a simple one myself. For other usages, I strongly recommend Boost Geometry library.
 *
 *        Version:  1.0
 *        Created:  Thu Oct 16 14:13:36 2014
 *
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TerryLu, terrylu87@gmail.com
 *        Company:  Terry's working house
 *
 * =====================================================================================
 */
#include "Geometry.h"
#include <cmath>

// for 3d point

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


// for 2d point

Vector2d::Vector2d(double _x,double _y,double _z)
{
    x = _x;
    y = _y;
}

Vector2d::~Vector2d()
{
    ;
}

Vector2d Vector2d::operator+(const Vector2d& p)
{
    Vector2d ret;
    ret.x = x + p.x;
    ret.y = y + p.y;
    return ret;
}

Vector2d Vector2d::operator-(const Vector2d& p)
{
    Vector2d ret;
    ret.x = x - p.x;
    ret.y = y - p.y;
    return ret;
}

double Vector2d::operator*(const Vector2d& p)
{
    return (x*p.x + y*p.y);
}

double Vector2d::operator^(const Vector2d& p)
{
    double ret=0;
    // ret.x = y*p.z - z*p.y;
    // ret.y = z*p.x - x*p.z;
    return ret;
}

std::ostream& operator<<(std::ostream& os, const Vector2d& v)
{
    return os << "(" << v.x << "," << v.y << ")";
}

//Compute the distance from AB to C
//if isSegment is true, AB is a segment, not a line.
double linePointDist(Point2d A, Point2d B, Point2d C, bool isSegment){
    // double dist = ((B-A)^(C-A)) / sqrt((B-A)*(B-A));
    // if(isSegment){
    //     int dot1 = (C-B)*(B-A);
    //     if(dot1 > 0)return sqrt((B-C)*(B-C));
    //     int dot2 = (C-A)*(A-B);
    //     if(dot2 > 0)return sqrt((A-C)*(A-C));
    // }
    // return abs(dist);
    return 0;
}

double linePointDist(Point3d A, Point3d B, Point3d C, bool isSegment)
{
    double ret=0;
    return ret;
}

// Line2d::Line2d(const Line2d& l)
// {
// }

Line2d::Line2d(const double& _a,const double& _b,const double& _c)
{
    A = _a;
    B = _b;
    C = _c;
}

Line2d::Line2d(const Point2d& a,const Point2d& b)
{
// A = y2-y1
// B = x1-x2
// C = A*x1+B*y1
    A = b.y - a.y;
    B = a.x - b.x;
    C = A*a.x + B*a.y;
}

bool isIntersected(const Line2d l1, const Line2d l2)
{
    // double det = A1*B2 - A2*B1;
    double det = l1.A * l2.B - l2.A * l1.B;
    if(det == 0) return false;
    else return true;
}

Point2d getIntersection(const Line2d l1, const Line2d l2)
{
    Point2d ret(INFINITY,INFINITY);

    double det = l1.A * l2.B - l2.A * l1.B;
    if(det == 0){
        return ret;
    }else{
        ret.x = (l2.B*l1.C - l1.B*l2.C)/det;
        ret.y = (l1.A*l2.C - l2.A*l1.C)/det;
        return ret;
    }
}
