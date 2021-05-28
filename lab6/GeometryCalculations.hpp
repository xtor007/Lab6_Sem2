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
    
    void getNormalVector(){
        vectorCoordinates[0].push_back(y2*z3 - y1*z3 - y2*z1 - y3*z2 + y3*z1 + y1*z2);
        vectorCoordinates[0].push_back(z2*x3 - z1*x3 - z2*x1 - z3*x2 + z3*x1 + x2*z1);
        vectorCoordinates[0].push_back(x2*y2 - x1*y3 - x2*y1 - x3*y2 + x3*y1 + x1*y2);
    }
    
    void getVectorToLightPoint(){
        vectorCoordinates[1].push_back(lightPointX-x1);
        vectorCoordinates[1].push_back(lightPointY-y1);
        vectorCoordinates[1].push_back(lightPointZ-z1);
    }
    
    float vectorModule(float x, float y, float z){
        return sqrt(pow(x, 2)+pow(y, 2)+pow(z, 2));
    }
    
public:
    Geometry(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float lightPointX, float lightPointY, float lightPointZ ) :
    x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2), x3(x3), y3(y3), z3(z3), lightPointX(lightPointX), lightPointY(lightPointY), lightPointZ(lightPointZ){
        vectorCoordinates.resize(2);
        getNormalVector();
        getVectorToLightPoint();
    }

    float getCos(){
        return ((vectorCoordinates[0][0]*vectorCoordinates[1][0]+vectorCoordinates[0][1]*vectorCoordinates[1][1]+vectorCoordinates[0][2]*vectorCoordinates[1][2])/(vectorModule(vectorCoordinates[0][0], vectorCoordinates[0][1], vectorCoordinates[0][2])*vectorModule(vectorCoordinates[1][0], vectorCoordinates[1][1], vectorCoordinates[1][2])));
    }
    
};


#endif /* GeometryCalculations_hpp */
