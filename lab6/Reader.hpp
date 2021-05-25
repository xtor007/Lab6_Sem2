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
    vector<double> vertexes;
    vector<Triangle> triangles;
    void Read(){
        path = "/Users/yaroslav/Desktop/Lab6_Sem2/Sourse/16434_Cow_v4_NEW.obj";
        ifstream fileRead(path);
        string line, bufferLine = "";
        if (fileRead.is_open()) {
            while (getline(fileRead, line)) {
                if (line[0] == 'v' && line[1] == ' ') {
                    bufferLine = line.erase(0, 2);
                }
            }
        }
        else{
            showMessage("There's to .obj file at the path: " + path, 1);
        }
    }
    void showMessage(string str, bool error = 0){
        cout << str << endl;
        if (error) exit(error);
    }
public:
    ObjReader(string path){
        this->path = path;
        Read();
    }
};



#endif /* Reader_hpp */
