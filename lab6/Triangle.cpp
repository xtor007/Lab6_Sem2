//
//  Triangle.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#include "Triangle.hpp"

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
