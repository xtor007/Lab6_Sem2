//
//  GeometryCalculations.cpp
//  lab6_sem2
//
//  Created by Берлинский Ярослав Владленович on 25.05.2021.
//

#include "GeometryCalculations.hpp"

void Geometry::getNormalVector(){
    vectorCoordinates[0].push_back(y2*z3 - y1*z3 - y2*z1 - y3*z2 + y3*z1 + y1*z2);
    vectorCoordinates[0].push_back(z2*x3 - z1*x3 - z2*x1 - z3*x2 + z3*x1 + x2*z1);
    vectorCoordinates[0].push_back(x2*y3 - x1*y3 - x2*y1 - x3*y2 + x3*y1 + x1*y2);
}

void  Geometry::getVectorToLightPoint(){
    vectorCoordinates[1].push_back(lightPointX-res[0]);
    vectorCoordinates[1].push_back(lightPointY-res[1]);
    vectorCoordinates[1].push_back(lightPointZ-res[2]);
}

float Geometry::vectorModule(float x, float y, float z){
    return sqrt(pow(x, 2)+pow(y, 2)+pow(z, 2));
}

float Geometry::getCos(){
    float res = ((vectorCoordinates[0][0]*vectorCoordinates[1][0]+vectorCoordinates[0][1]*vectorCoordinates[1][1]+vectorCoordinates[0][2]*vectorCoordinates[1][2])/(vectorModule(vectorCoordinates[0][0], vectorCoordinates[0][1], vectorCoordinates[0][2])*vectorModule(vectorCoordinates[1][0], vectorCoordinates[1][1], vectorCoordinates[1][2])));
    return res ;//>=0 ? res : -1;
}

void Geometry::findInternalDotCoordinates(){
    vector<float> medianPoint(3);
    res.resize(3);
    medianPoint[0] = (x2 + x3)/2;
    medianPoint[1] = (y2 + y3)/2;
    medianPoint[2] = (z2 + z3)/2;
    res[0] = (x1+medianPoint[0])/2;
    res[1] = (y1+medianPoint[1])/2;
    res[2] = (z1+medianPoint[2])/2;
}


Geometry::Geometry(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float lightPointX, float lightPointY, float lightPointZ ) :
x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2), x3(x3), y3(y3), z3(z3), lightPointX(lightPointX), lightPointY(lightPointY), lightPointZ(lightPointZ){
    findInternalDotCoordinates();
    vectorCoordinates.resize(2);
    getNormalVector();
    getVectorToLightPoint();
}
