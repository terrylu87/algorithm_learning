/*
 * =====================================================================================
 *
 *       Filename:  Geometry2d.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Sat Oct 18 15:15:20 2014
 *
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TerryLu, terrylu87@gmail.com
 *        Company:  Terry's working house
 *
 * =====================================================================================
 */

#ifndef _GEOMETRY2D_H_
#define _GEOMETRY2D_H_

#include <iostream>
#include "GeometryDefine.h"

class Vector2d{
public:
    Vector2d(double _x,double _y);
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
    /* Line2d(const double& slope,const Point2d& p); */
    double A;
    double B;
    double C;
};

class Circle2d{
public:
    Circle2d(const Point2d& c, double r);
    Circle2d(const Point2d& a, const Point2d& b, const Point2d& c);
    Point2d center;
    double radius;
};

double linePointDist(
    const Point2d& A,
    const Point2d& B,
    const Point2d& C,
    bool isSegment);

double getDistance(const Point2d& a, const Point2d& b);
/* double getDistance(const Point2d& A, , bool isSegment); */
double linePointDist(
    Point2d A,
    Point2d B,
    Point2d C,
    bool isSegment);
bool isIntersected(const Line2d& l1, const Line2d& l2);
Point2d getIntersection(const Line2d& l1, const Line2d& l2);
Line2d perpendicular_bisectors(const Point2d& a, const Point2d& b);

/* Line-Line Intersection */
/* Finding a Circle From 3 Points */
/* Reflection */
/* Rotation */
/* Convex Hull */

#endif /* _GEOMETRY2D_H_ */
