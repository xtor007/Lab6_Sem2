//
//  Area.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#include "Area.hpp"

void Area::addToArea(Triangle *newData) {
    for (int i=0; i<3; i++) {
        if (count == 0) {
            pointMax.push_back(newData->getMax(i));
            pointMin.push_back(newData->getMin(i));
        } else {
            if (newData->getMax(i) > pointMax[i]) {
                pointMax[i] = newData->getMax(i);
            }
            if (newData->getMin(i) < pointMin[i]) {
                pointMin[i] = newData->getMin(i);
            }
        }
    }
    count++;
}

bool Area::isInArea(Ray ray) {
    //return true;
    vector<float> minT;
    vector<float> maxT;
    bool flag = true;
    for (int i=0; i<3; i++) {
        if (ray.directionVector[i] > 0) {
            minT.push_back((pointMin[i]-ray.stPoint[i])/ray.directionVector[i]);
            maxT.push_back((pointMax[i]-ray.stPoint[i])/ray.directionVector[i]);
        } else if (ray.directionVector[i] < 0) {
            maxT.push_back((pointMin[i]-ray.stPoint[i])/ray.directionVector[i]);
            minT.push_back((pointMax[i]-ray.stPoint[i])/ray.directionVector[i]);
        } else {
            return true;
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (minT[i] > maxT[j]) {
                flag = false;
                return false;
            }
        }
    }
    return flag;
}

/*
 x = x0 + at
 y = y0 + bt
 z = z0 + ct
 */

float Area::distToArea(Triangle *from) {
    float res = 0;
    for (int i=0; i<3; i++) {
        res += (from->getMax(i)-pointMax[i])*(from->getMax(i)-pointMax[i]);
    }
    return sqrt(res);
}


