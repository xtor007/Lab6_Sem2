//
//  Ray.hpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//


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
     толичка, сорри
     */
public:
    vector<float> stPoint;
    vector<float> directionVector;
    
<<<<<<< HEAD
    Ray(float x0, float y0, float z0, float a, float b, float c);
    vector<float> pointInZ (float z);
=======
    Ray(float source_x, float source_y, float source_z, float inter_x, float inter_y, float inter_z);
    vector<int> pointInZ (int z);
>>>>>>> frame
};

