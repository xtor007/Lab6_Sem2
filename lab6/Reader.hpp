//
//  Reader.hpp
//  lab6_sem2
//
//  Created by Берлинский Ярослав Владленович on 25.05.2021.
//

#ifndef Reader_hpp
#define Reader_hpp

#include <iostream>
#include <vector>
#include <fstream>
#include "Triangle.hpp"
#include "GeometryCalculations.hpp"
#include <string>

using namespace std;

class ObjReader{
    string path;
    vector<vector<float>> vertexes;
    /// hardcode
    float lightPointX = 5.0, lightPointY = 5.0, lightPointZ = 5.0; // luminary
    /// hardcode end

    vector<float> getPointFromLine(string line);
    vector<int> getTriangeFromLine(string line);
    void Read();
    
    void showMessage(string str, bool error = 0);
    
    float getCosAplha(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
    
public:
    vector<Triangle> triangles;
    ObjReader(string path);
    void output();
};


#endif /* Reader_hpp */
