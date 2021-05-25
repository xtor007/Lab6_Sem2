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

using namespace std;

class ObjReader{
    string path;
    vector<double *> vertexes;
    void Read(){
        ifstream fileRead(path);
        string line, bufferLine = "";
        if (fileRead.is_open()) {
            while (getline(fileRead, line)) {
                if (line[0] == 'v' && line[1] == ' ') {
                    vertexes.push_back(getPointFromLine(line.erase(0, 2)));
                }
                else if (line[0] == 'f' && line[1] == ' ') {
                    int *triangle = getTriangeFromLine(line.erase(0, 2));
                    Triangle temp(vertexes[triangle[0]][0], vertexes[triangle[0]][1], vertexes[triangle[0]][2], vertexes[triangle[1]][0], vertexes[triangle[1]][1], vertexes[triangle[1]][2], vertexes[triangle[2]][0], vertexes[triangle[2]][1], vertexes[triangle[2]][2], 0.5);
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
public:
    vector<Triangle> triangles;
    ObjReader(string path){
        this->path = path;
        Read();
    }
    double *getPointFromLine(string line){
        double *point3D = new double[3];
        int counter = 0;
        string buffer = "";
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ' && i != line.size() - 1) {
                buffer += line[i];
            }
            else {
                if (i == line.size() - 1) buffer += line[i];
                point3D[counter] = stod(buffer);
                counter++; buffer = "";
            }
        }
        
        return point3D;
    }
    int *getTriangeFromLine(string line){
        int *Points = new int[3];
        int counter = 0;
        string buffer = "";
        bool flag = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != '/' && !flag) {
                buffer += line[i];
            }
            else if (buffer.size() > 0){
                flag = 1;
                cout << buffer << endl;
                Points[counter] = stoi(buffer); buffer = "";
                ++counter;
            }
            if (line[i] == ' ') flag = 0;
        }
        
        return Points;
    }
    void output(){
        cout << vertexes.size();
        for (int i = 0; i < vertexes.size(); i++) {
            cout << vertexes[i][0] << "\t" << vertexes[i][1] << "\t" << vertexes[i][2] << endl;
        }
    }
};



#endif /* Reader_hpp */
