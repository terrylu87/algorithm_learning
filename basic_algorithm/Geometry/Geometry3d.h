/*
 * =====================================================================================
 *
 *       Filename:  Geometry3d.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  Sat Oct 18 15:21:51 2014
 *
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  TerryLu, terrylu87@gmail.com
 *        Company:  Terry's working house
 *
 * =====================================================================================
 */

#ifndef _GEOMETRY3D_H_
#define _GEOMETRY3D_H_

#include <iostream>
#include "GeometryDefine.h"

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

/* double linePointDist(const Point3d& A, */
/*     const Point3d& B, */
/*     const Point3d& C, */
/*     bool isSegment); */

#endif /* _GEOMETRY3D_H_ */
