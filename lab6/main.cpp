//
//  main.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 18.05.2021.
//

#include <iostream>
#include "Tree.hpp"
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
    return 0;
}
