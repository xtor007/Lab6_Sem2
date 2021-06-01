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
    
    //cout << "reading end";
    
    //Triangle big(0.2, 0.2, 0.1, -0.1, -0.1, -0.2, -0.1, 0.1, -0.1, 0.5);
    //Triangle dop(10000000, 10000000, 100000000, -2000000, -2000000, -2000000, -1000, 2000000, -30000, 0.6);
    //tree.addToTree(&big);
    //tree.addToTree(&dop);
    
//    Ray ray(0, 0, 0, 0, 0, 1);
//
//    cout << tree.findInTree(ray);
//
    
    
    
    int h = 720, w = 1024;
    //int h = 20, w = 20;
    
    Frame frame(h, w, tree);
    float** pixelMat = frame.getFrame();
    
//    for (int i=0; i<h; i++) {
//        for (int j=0; j<w; j++) {
//            cout << pixelMat[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    //cout << "frame end";
    
    bmpWriter writer("test.bmp", pixelMat, h, w);
    writer.bmpWrite();
    return 0;
}
