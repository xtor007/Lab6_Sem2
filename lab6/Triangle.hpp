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
using namespace std;

class Triangle {
    vector<int> point1; //0-координата х, 1-у, 2-z
    vector<int> point2;
    vector<int> point3;
    float color;
public:
    Triangle (int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, float cosAlpha) {
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
    
    float getColor() {
        return color;
    }
    
    int getMax(int numCoor) {
        if ((point1[numCoor] > point2[numCoor]) && (point1[numCoor] > point2[numCoor])) {
            return point1[numCoor];
        } else if (point2[numCoor] > point3[numCoor]) {
            return point2[numCoor];
        } else {
            return point3[numCoor];
        }
    }
};

#endif /* Triangle_hpp */
