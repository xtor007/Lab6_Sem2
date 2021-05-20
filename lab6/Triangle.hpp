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
    vector<int> point1; //0-координата х, 1-у, 2-z
    vector<int> point2;
    vector<int> point3;
    float color;
    bool isIn2dTriangle(vector<vector<int>> trianglePoints, vector<int> findPoint);
public:
    Triangle (int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, float cosAlpha);
    float getColor();
    int getMax(int numCoor);
    int getMin(int numCoor);
    bool isInTriangle(Ray ray);
};

#endif /* Triangle_hpp */
