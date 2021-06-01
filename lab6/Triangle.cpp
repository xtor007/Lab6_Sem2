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
    double t, u, v;

    SUB(edge1, point2, point1);
    SUB(edge2, point3, point1);

    CROSS(pvec, ray.directionVector, edge2);

    det = DOT(edge1, pvec);

    if(det < EPSILON) {
        return 0;
    }

    SUB(tvec, ray.stPoint, point1)

    u = DOT(tvec, pvec);
    if (u < 0.0 || u > det)
        return 0;

    CROSS(qvec, tvec, edge1);

    v = DOT(ray.stPoint, qvec);
    if (v < 0.0 || u + v > det)
        return 0;


//    if (det > -EPSILON && det < EPSILON) {
//        return 0;
//    }
//
//    inv_det = 1.0 / det;
//
//    SUB(tvec, ray.stPoint, point1);
//
//    u = DOT(tvec, pvec) * inv_det;
//    if (u < 0.0 || u > 1.0)
//        return 0;
//
//    CROSS(qvec, tvec, edge1);
//
//    v = DOT(ray.directionVector, qvec) * inv_det;
//    if (v < 0.0 || v > 1.0)
//        return 0;
//
//    t = DOT(edge2, qvec) * inv_det;
////    if (t < 0.0) //|| t > 1.0)
////        return 0;
//
//    return 1;
}

Triangle::Triangle (float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float cosAlpha) {
    point1.push_back(x1);
    point1.push_back(y1);
    point1.push_back(z1);
    point2.push_back(x2);
    point2.push_back(y2);
    point2.push_back(z2);
    point3.push_back(x3);
    point3.push_back(y3);
    point3.push_back(z3);
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

bool Triangle::isInTriangle(Ray ray) {
    vector<Ray> altRay;
    vector<vector<float>> triangleIn2d;
    vector<float> pointInXoY;
    if ((point1[2] != point2[2]) || (point2[2] != point3[2])) {
        altRay.push_back(Ray(point1[0], point1[1], point1[2], ray.directionVector[0]+point1[0], ray.directionVector[1]+point1[1], ray.directionVector[2]+point1[2]));
        altRay.push_back(Ray(point2[0], point2[1], point2[2], ray.directionVector[0]+point2[0], ray.directionVector[1]+point2[1], ray.directionVector[2]+point2[2]));
        altRay.push_back(Ray(point3[0], point3[1], point3[2], ray.directionVector[0]+point3[0], ray.directionVector[1]+point3[1], ray.directionVector[2]+point3[2]));
        for (int i=0; i<3; i++) {
            triangleIn2d.push_back(altRay[i].pointInZ(0));
        }
        pointInXoY = ray.pointInZ(0);
    } else {
        vector<float> temp = {point1[0], point1[1]};
        triangleIn2d.push_back(temp);
        temp = {point2[0], point2[1]};
        triangleIn2d.push_back(temp);
        temp = {point3[0], point3[1]};
        triangleIn2d.push_back(temp);
        pointInXoY = ray.pointInZ(point1[2]);
    }
    return isIn2dTriangle(triangleIn2d, pointInXoY);
}

bool Triangle::isIn2dTriangle(vector<vector<float>> trianglePoints, vector<float> findPoint) {
    trianglePoints.push_back(trianglePoints[0]);
    trianglePoints.push_back(trianglePoints[1]);
    float k1 = 0; float k2 = 0;
    bool isIn = true;
    for (int i = 0; i<3; i++) {
        if ((trianglePoints[i+1][0] - trianglePoints[i][0]) != 0) {
            k1 += (findPoint[0] - trianglePoints[i][0])/(trianglePoints[i+1][0] - trianglePoints[i][0]);
        }
        if ((trianglePoints[i+1][1] - trianglePoints[i][1]) != 0) {
            k1 += (findPoint[1] - trianglePoints[i][1])/(trianglePoints[i+1][1] - trianglePoints[i][1]);
        }
        if ((trianglePoints[i+1][0] - trianglePoints[i][0]) != 0) {
            k2 += (trianglePoints[i+2][0] - trianglePoints[i][0])/(trianglePoints[i+1][0] - trianglePoints[i][0]);
        }
        if ((trianglePoints[i+1][1] - trianglePoints[i][1]) != 0) {
            k2 += (trianglePoints[i+2][1] - trianglePoints[i][1])/(trianglePoints[i+1][1] - trianglePoints[i][1]);
        }
        if (k1*k2 < 0) {
            isIn = false;
        }
    }
    findPoint.push_back(1);
    return isIn;
}

bool Triangle::rayTriangleIntersect(Ray ray) {
    
    //return true;
    Vec3f orig(ray.stPoint[0],ray.stPoint[1],ray.stPoint[2]);
    Vec3f dir(ray.directionVector[0]+ray.stPoint[0],ray.directionVector[1]+ray.stPoint[1],ray.directionVector[2]+ray.stPoint[2]);
    
    Vec3f v0(point1[0],point1[1],point1[2]);
    Vec3f v1(point2[0],point2[1],point2[2]);
    Vec3f v2(point3[0],point3[1],point3[2]);
//    Vec3f v0(1,1,1);
//    Vec3f v1(1,1,1);
//    Vec3f v2(1,1,1);
    
    constexpr float kEpsilon = 1e-8;
    // compute plane's normal
    Vec3f v0v1 = v1 - v0;
    Vec3f v0v2 = v2 - v0;
    // no need to normalize
    Vec3f N = v0v1.crossProduct(v0v2); // N
    float area2 = N.length(); 
 
    // Step 1: finding P
 
    // check if ray and plane are parallel ?
    float NdotRayDirection = N.dotProduct(dir); 
    if (fabs(NdotRayDirection) < kEpsilon) // almost 0
        return false; // they are parallel so they don't intersect !
 
    // compute d parameter using equation 2
    float d = N.dotProduct(v0);
 
    // compute t (equation 3)
    float t = (N.dotProduct(orig) + d) / NdotRayDirection;
    // check if the triangle is in behind the ray
    
    if (t < 0) return false; // the triangle is behind
 
    // compute the intersection point using equation 1
    Vec3f P = orig + t * dir;
 
    // Step 2: inside-outside test
    Vec3f C; // vector perpendicular to triangle's plane
 
    // edge 0
    Vec3f edge0 = v1 - v0; 
    Vec3f vp0 = P - v0;
    C = edge0.crossProduct(vp0);
    
    if (N.dotProduct(C) < 0) return false; // P is on the right side
 
    // edge 1
    Vec3f edge1 = v2 - v1;
    Vec3f vp1 = P - v1;
    C = edge1.crossProduct(vp1);
    if (N.dotProduct(C) < 0)  return false; // P is on the right side
 
    // edge 2
    Vec3f edge2 = v0 - v2;
    Vec3f vp2 = P - v2;
    C = edge2.crossProduct(vp2);
    if (N.dotProduct(C) < 0) return false; // P is on the right side;
 
    return true; // this ray hits the triangle
}
