/*
 * =====================================================================================
 *
 *       Filename:  Geometry.h
 *
 *    Description:  Geometric algorithms using in topcoder. Because topcoder does not allow Boost. I have to implement a simple one myself. For other usages, I strongly recommend Boost Geometry library.
 *
 *        Version:  1.0
 *        Created:  Fri Oct 17 10:42:44 2014
 *
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TerryLu, terrylu87@gmail.com
 *        Company:  Terry's working house
 *
 * =====================================================================================
 */

#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <iostream>
#include <limits>       // std::numeric_limits

const double INFINITY = std::numeric_limits<double>::infinity();

class Vector3d{
public:
    Vector3d(double _x=0,double _y=0,double _z=0);
    /* Vector(const Point& a, const Point& b); */
    ~Vector3d();
    friend std::ostream& operator<<(std::ostream& os, const Vector3d& v);
    Vector3d operator+ (const Vector3d& p);
    Vector3d operator- (const Vector3d& p);
    double operator* (const Vector3d& p);
    Vector3d operator^ (const Vector3d& p);
    double x;
    double y;
    double z;
};

typedef Vector3d Point3d;

class Vector2d{
public:
    Vector2d(double _x=0,double _y=0,double _z=0);
    /* Vector(const Point& a, const Point& b); */
    ~Vector2d();
    friend std::ostream& operator<<(std::ostream& os, const Vector2d& v);
    Vector2d operator+ (const Vector2d& p);
    Vector2d operator- (const Vector2d& p);
    double operator* (const Vector2d& p);
    double operator^ (const Vector2d& p);
    double x;
    double y;
};

typedef Vector2d Point2d;

/* a line in 2 dimension can be describe as Ax + By = C */
class Line2d{
public:
    /* Line2d(const Line2d& l); */
    Line2d(const double& _a,const double& _b,const double& _c);
    Line2d(const Point2d& a,const Point2d& b);
    double A;
    double B;
    double C;
};

double linePointDist(Point2d A, Point2d B, Point2d C, bool isSegment);
double linePointDist(Point3d A, Point3d B, Point3d C, bool isSegment);

/* Line-Line Intersection */
bool isIntersected(const Line2d l1, const Line2d l2);
Point2d getIntersection(const Line2d l1, const Line2d l2);
/* Finding a Circle From 3 Points */
/* Reflection */
/* Rotation */
/* Convex Hull */

#endif /* _GEOMETRY_H_ */

