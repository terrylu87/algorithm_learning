/*
 * =====================================================================================
 *
 *       Filename:  Geometry2d.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Sat Oct 18 15:18:04 2014
 *
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TerryLu, terrylu87@gmail.com
 *        Company:  Terry's working house
 *
 * =====================================================================================
 */
#include "Geometry2d.h"
#include <cmath>

// begin of Vector2d definition
Vector2d::Vector2d(double _x=0,double _y=0)
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
    return x*p.y - y*p.x;
}

std::ostream& operator<<(std::ostream& os, const Vector2d& v)
{
    return os << "(" << v.x << "," << v.y << ")";
}
// end of Vector2d definition

// begin of Line2d definition
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
// end of Line2d definition

// begin of Class Circle2d
Circle2d::Circle2d(const Point2d& c, double r)
{
    center = c;
    radius = r;
}

Circle2d::Circle2d(const Point2d& a, const Point2d& b, const Point2d& c)
{
    Line2d lpb1 = perpendicular_bisectors(a,b);
    Line2d lpb2 = perpendicular_bisectors(b,c);
    center = getIntersection(lpb1,lpb2);
    radius = getDistance(a,center);
}
// end of Class Circle2d

// begin of Utility functions
bool isIntersected(const Line2d l1, const Line2d l2)
{
    // double det = A1*B2 - A2*B1;
    double det = l1.A * l2.B - l2.A * l1.B;
    if(det == 0) return false;
    else return true;
}

//Compute the distance from AB to C
//if isSegment is true, AB is a segment, not a line.
double linePointDist(
    Point2d A,
    Point2d B,
    Point2d C,
    bool isSegment)
{
    double dist = ((B-A)^(C-A)) / sqrt((B-A)*(B-A));
    if(isSegment){
        int dot1 = (C-B)*(B-A);
        if(dot1 > 0)return sqrt((B-C)*(B-C));
        int dot2 = (C-A)*(A-B);
        if(dot2 > 0)return sqrt((A-C)*(A-C));
    }
    return std::abs(dist);
}

Point2d getIntersection(const Line2d& l1, const Line2d& l2)
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

Line2d perpendicular_bisectors(const Point2d& a, const Point2d& b)
{
    // Line2d ret(-1/getSlope(a,b),getMidPoint(a,b));
    Line2d lab(a,b);
    double A,B,C;
    A = -lab.B;
    B = lab.A;
    C = A*(b.x-a.x)/2 + B*(b.y-a.y)/2;
    Line2d ret(A,B,C);
    return ret;
}

double getDistance(const Point2d& a, const Point2d& b)
{
    return sqrt(pow(b.x-a.x,2) + pow(b.y-a.y,2));
}
// end of Utility functions