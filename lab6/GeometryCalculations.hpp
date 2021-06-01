//
//  GeometryCalculations.hpp
//  lab6_sem2
//
//  Created by Берлинский Ярослав Владленович on 25.05.2021.
//

#ifndef GeometryCalculations_hpp
#define GeometryCalculations_hpp
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Geometry{
    float x1, y1, z1, x2, y2, z2, x3, y3, z3;
    float lightPointX = 5, lightPointY = 5, lightPointZ = 5;
    vector<vector<float>> vectorCoordinates;
    
    void getNormalVector();
    
    void getVectorToLightPoint();
    
    float vectorModule(float x, float y, float z);
    
public:
    Geometry(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float lightPointX, float lightPointY, float lightPointZ );
    float getCos();
    
};


#endif /* GeometryCalculations_hpp */
