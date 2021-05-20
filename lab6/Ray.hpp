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
    vector<int> stPoint;
    vector<int> directionVector;
    
    Ray(int x0, int y0, int z0, int a, int b, int c);
};

#endif /* Ray_hpp */
