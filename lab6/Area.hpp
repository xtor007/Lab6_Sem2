//
//  Area.hpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#ifndef Area_hpp
#define Area_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Triangle.hpp"
using namespace std;

class Area {
    vector<float> pointMax;
    vector<float> pointMin;
public:
    int count = 0;
    
    void addToArea(Triangle *newData);
    bool isInArea(Ray ray);
    float distToArea(Triangle *from);
};

#endif /* Area_hpp */
