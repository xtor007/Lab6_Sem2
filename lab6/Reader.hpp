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
    vector<float> getPointFromLine(string line){
        vector<float> point3D;
        string buffer = "";
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ' && i != line.size() - 1) {
                buffer += line[i];
            }
            else {
                if (i == line.size() - 1) buffer += line[i];
                point3D.push_back(stod(buffer));
                buffer = "";
            }
        }
        
        return point3D;
    }
    vector<int> getTriangeFromLine(string line){
        vector<int> Points;
        string buffer = "";
        bool flag = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != '/' && !flag) {
                buffer += line[i];
            }
            else if (buffer.size() > 0){
                flag = 1;
                Points.push_back(stoi(buffer)); buffer = "";
            }
            if (line[i] == ' ') flag = 0;
        }
        
        return Points;
    }
    void Read(){
        ifstream fileRead(path);
        string line, bufferLine = "";
        if (fileRead.is_open()) {
            while (getline(fileRead, line)) {
                if (line[0] == 'v' && line[1] == ' ') {
                    vertexes.push_back(getPointFromLine(line.erase(0, 2)));
                }
                else if (line[0] == 'f' && line[1] == ' ') {
                    line.erase(0, 2);
                    vector<int> triangle = getTriangeFromLine(line);
                    // getting cosinus
                    Geometry geo(vertexes[triangle[0]-1][0], vertexes[triangle[0]-1][1], vertexes[triangle[0]-1][2], vertexes[triangle[1]-1][0], vertexes[triangle[1]-1][1], vertexes[triangle[1]-1][2], vertexes[triangle[2]-1][0], vertexes[triangle[2]-1][1], vertexes[triangle[2]-1][2], lightPointX, lightPointY, lightPointZ);
                    float cos = geo.getCos();
                    // getting triangle
                    Triangle temp(vertexes[triangle[0]-1][0], vertexes[triangle[0]-1][1], vertexes[triangle[0]-1][2], vertexes[triangle[1]-1][0], vertexes[triangle[1]-1][1], vertexes[triangle[1]-1][2], vertexes[triangle[2]-1][0], vertexes[triangle[2]-1][1], vertexes[triangle[2]-1][2], cos);

                    triangles.push_back(temp);
                }
            }
        }
        else{
            showMessage("There's to .obj file at the path: " + path, 0);
        }
    }
    
    void showMessage(string str, bool error = 0){
        cout << str << endl;
        if (error) exit(error);
    }
    
    float getCosAplha(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
        Geometry geo(x1, y1, z1, x2, y2, z2, x3, y3, z3, lightPointX, lightPointY, lightPointZ);
        return geo.getCos();
    }
    
public:
    vector<Triangle> triangles;
    ObjReader(string path){
        this->path = path;
        Read();
    }
    void output(){
        cout << vertexes.size();
        for (int i = 0; i < vertexes.size(); i++) {
            cout << vertexes[i][0] << "\t" << vertexes[i][1] << "\t" << vertexes[i][2] << endl;
        }
    }
};


#endif /* Reader_hpp */
