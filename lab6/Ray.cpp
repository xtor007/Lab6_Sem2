//
//  Ray.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#include "Ray.hpp"

Ray::Ray(float x0, float y0, float z0, float a, float b, float c) {
    stPoint.push_back(x0);
    stPoint.push_back(y0);
    stPoint.push_back(z0);
    directionVector.push_back(a);
    directionVector.push_back(b);
    directionVector.push_back(c);
}

vector<float> Ray::pointInZ(float z) {
    vector<float> res;
    res.push_back(((z-stPoint[2])*directionVector[0]/directionVector[2]) + stPoint[0]);
    res.push_back(((z-stPoint[2])*directionVector[1]/directionVector[2]) + stPoint[1]);
    return res;
}
