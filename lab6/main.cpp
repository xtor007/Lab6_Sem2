//
//  main.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 18.05.2021.
//

#include <iostream>
#include "Tree.hpp"
#include "Frame.hpp"

int main(int argc, const char * argv[]) {
    Tree tree;
    vector<Triangle> data;
    Triangle toAdd = Triangle(0, 0, 0, 1, 2, 3, -1, 4, 7, 0.5);
    data.push_back(toAdd);
    toAdd = Triangle(0, 1, 4, -1, 6, 3, -1, 4, 8, 0.6);
    data.push_back(toAdd);
    toAdd = Triangle(2, -1, 5, 1, 6, 5, -1, 4, 4, 0.7);
    data.push_back(toAdd);
    for (int i=0; i<data.size(); i++) {
        tree.addToTree(&data[i]);
    }

    int h = 25, w = 50;
    Frame frame(h, w, tree);
    float** res = frame.getFrame();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
