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
#include "Ray.hpp"
using namespace std;

class Triangle {
    vector<float> point1; //0-координата х, 1-у, 2-z
    vector<float> point2;
    vector<float> point3;
    float color;
    bool isIn2dTriangle(vector<vector<float>> trianglePoints, vector<float> findPoint);
public:
    Triangle (float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float cosAlpha);
    float getColor();
    int getMax(int numCoor);
    int getMin(int numCoor);
    bool isInTriangle(Ray ray);
};

#endif /* Triangle_hpp */
