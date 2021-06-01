//
//  Ray.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#include "Ray.hpp"



Ray::Ray(float source_x, float source_y, float source_z, float inter_x, float inter_y, float inter_z) {
    stPoint = { source_x, source_y, source_z };
    directionVector = { inter_x - source_x, inter_y - source_y, inter_z - source_z };
}