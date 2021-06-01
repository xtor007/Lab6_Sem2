//
//  main.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 18.05.2021.
//

#include <iostream>
#include "Tree.hpp"
#include "Reader.hpp"
#include "Frame.hpp"
#include "bmpWriter.hpp"

int main(int argc, const char * argv[]) {
    Tree tree;
    string path = "untitled.obj";
    ObjReader reader(path);
    vector<Triangle> data = reader.triangles;
    for (int i=0; i<data.size();i++) {
        tree.addToTree(&data[i]);
    }
   
    int h = 1024, w = 1024;
    
    Frame frame(h, w, tree);
    float** pixelMat = frame.getFrame();
    
    bmpWriter writer("test.bmp", pixelMat, h, w);
    writer.bmpWrite();
    return 0;
}
