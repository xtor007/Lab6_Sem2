//
//  Triangle.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#include "Triangle.hpp"

#define EPSILON 0.0000001
#define CROSS(dest, v1, v2) dest[0] = v1[1] * v2[2] - v1[2] * v2[1]; \
                            dest[1] = v1[2] * v2[0] - v1[0] * v2[2]; \
                            dest[2] = v1[0] * v2[1] - v1[1] * v2[0];
#define DOT(v1, v2) (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2])
#define SUB(dest, v1, v2) dest[0] = v1[0] - v2[0]; \
                          dest[1] = v1[1] - v2[1]; \
                          dest[2] = v1[2] - v2[2];

int Triangle::intersect_triangle(Ray ray) {
    double edge1[3], edge2[3], tvec[3], pvec[3], qvec[3];
    double det, inv_det;
    double u, v;

    SUB(edge1, point2, point1);
    SUB(edge2, point3, point1);

    CROSS(pvec, ray.directionVector, edge2);

    det = DOT(edge1, pvec);

<<<<<<< Updated upstream
=======


>>>>>>> Stashed changes
    if (det > -EPSILON && det < EPSILON) {
        return 0;
    }

    inv_det = 1.0 / det;

    SUB(tvec, ray.stPoint, point1);

    u = DOT(tvec, pvec) * inv_det;
    if (u < 0.0 || u > 1.0)
        return 0;

    CROSS(qvec, tvec, edge1);

    v = DOT(ray.directionVector, qvec) * inv_det;
    if (v < 0.0 || u + v > 1.0)
        return 0;

<<<<<<< Updated upstream
=======
    t = DOT(edge2, qvec) * inv_det;


>>>>>>> Stashed changes
    return 1;
} 

Triangle::Triangle (float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float cosAlpha) {
    point1 = { x1, y1, z1 };
    point2 = { x2, y2, z2 };
    point3 = { x3, y3, z3 };
    color = cosAlpha;
}

float Triangle::getColor() {
    return color;
}




float Triangle::getMax(int numCoor) {
    if ((point1[numCoor] > point2[numCoor]) && (point1[numCoor] > point3[numCoor])) {
        return point1[numCoor];
    } else if (point2[numCoor] > point3[numCoor]) {
        return point2[numCoor];
    } else {
        return point3[numCoor];
    }
}

float Triangle::getMin(int numCoor) { 
    if ((point1[numCoor] < point2[numCoor]) && (point1[numCoor] < point3[numCoor])) {
        return point1[numCoor];
    } else if (point2[numCoor] < point3[numCoor]) {
        return point2[numCoor];
    } else {
        return point3[numCoor];
    }
}
