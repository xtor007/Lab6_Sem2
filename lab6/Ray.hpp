//
//  Ray.hpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#ifndef Ray_hpp
#define Ray_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Ray {
    /*
     прямая задается параметрическим уравнением:
     x = x0 + a*t
     y = y0 + b*t
     z = z0 + c*t
     */
public:
    vector<float> stPoint;
    vector<float> directionVector;
    
    Ray(float x0, float y0, float z0, float a, float b, float c);
    vector<float> pointInZ (float z);
};

#endif /* Ray_hpp */
