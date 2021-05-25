//
//  main.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 18.05.2021.
//

#include <iostream>
#include "Tree.hpp"
<<<<<<< HEAD
#include "Reader.hpp"

int main(int argc, const char * argv[]) {
    Tree tree;
    string path = "cow.obj";
    ObjReader reader(path);
    vector<Triangle> data = reader.triangles;
    for (int i=0; i<data.size();i++) {
        tree.addToTree(&data[i]);
    }
    cout << 1;
=======
#include "Frame.hpp"
#include "bmpWriter.hpp"

int main(int argc, const char * argv[]) {
    Tree tree;
    vector<Triangle> data;
    Triangle toAdd = Triangle(0, 0, 0, 1, 2, 3, -1, 4, 7, 0.5);
    data.push_back(toAdd);
    toAdd = Triangle(0, 1, 4, -1, 6, 3, -1, 4, 8, 0.6);
    data.push_back(toAdd);
    toAdd = Triangle(7, 0, 0, 8, 1, 0, 8, 10, 5, 0.13);         //(2, -1, 5, 1, 6, 5, -1, 4, 4, 0.7);
    data.push_back(toAdd);
    for (int i=0; i<data.size(); i++) {
        tree.addToTree(&data[i]);
    }

    int h = 250, w = 500;
    Frame frame(h, w, tree);
    float** res = frame.getFrame();
    bmpWriter writer("test.bmp", res, h, w);
    writer.bmpWrite();
>>>>>>> frame
    return 0;
}
