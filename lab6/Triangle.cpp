//
//  Triangle.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#include "Triangle.hpp"

Triangle::Triangle (int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, float cosAlpha) {
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

int Triangle::getMax(int numCoor) {
    if ((point1[numCoor] > point2[numCoor]) && (point1[numCoor] > point2[numCoor])) {
        return point1[numCoor];
    } else if (point2[numCoor] > point3[numCoor]) {
        return point2[numCoor];
    } else {
        return point3[numCoor];
    }
}

int Triangle::getMin(int numCoor) {
    if ((point1[numCoor] < point2[numCoor]) && (point1[numCoor] < point2[numCoor])) {
        return point1[numCoor];
    } else if (point2[numCoor] < point3[numCoor]) {
        return point2[numCoor];
    } else {
        return point3[numCoor];
    }
}
