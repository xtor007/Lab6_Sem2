//
//  Ray.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#include "Ray.hpp"



Ray::Ray(float source_x, float source_y, float source_z, float inter_x, float inter_y, float inter_z) {
    stPoint = { source_x, source_y, source_z };
    //stPoint = {inter_x, inter_y, inter_z};
    directionVector = { inter_x - source_x, inter_y - source_y, inter_z - source_z };
}

vector<float> Ray::pointInZ(float z) {   
    vector<float> res;
    res.push_back(((z-stPoint[2])*directionVector[0]/directionVector[2]) + stPoint[0]);
    res.push_back(((z-stPoint[2])*directionVector[1]/directionVector[2]) + stPoint[1]);
    return res;
}
