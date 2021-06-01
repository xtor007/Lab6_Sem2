//
//  Triangle.hpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
//#include "Ray.hpp"
#include "GeometryCalculations.hpp"
//#include <cc>
using namespace std;

class Triangle {
    Point point1, point2, point3; //0-координата х, 1-у, 2-z
    float colorR, colorG, colorB;
public:
    Triangle (float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float colorR, float colorG, float colorB);
    float* getColor();
    float getMax(int numCoor);
    float getMin(int numCoor);
    int intersect_triangle(Ray ray);
};

#endif /* Triangle_hpp */
