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
//    string path = "cow.obj";
//    ObjReader reader(path);
//    vector<Triangle> data = reader.triangles;
//    for (int i=0; i<data.size();i++) {
//        tree.addToTree(&data[i]);
//    }
    
    Triangle big(-0.1, -0.2, -0.5, -0.98, 0, 0.2, 0.98, 0.1, 0.1, 0.5);
    tree.addToTree(&big);
    
    
    
    int h = 250, w = 500;
    //int h = 20, w = 20;
    Frame frame(h, w, tree);
    float** pixelMat = frame.getFrame();
    
//    for (int i=0; i<h; i++) {
//        for (int j=0; j<w; j++) {
//            cout << pixelMat[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    bmpWriter writer("test.bmp", pixelMat, h, w);
    writer.bmpWrite();
    return 0;
}
