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
    Ray ray = Ray(0, 0, 1, 1, 1, 1);
    cout << tree.findInTree(ray) << endl;
    ObjReader g("df");
    double *r = g.getPointFromLine("0.45667 0.678 -0.7885");
    cout << r[0] << " " << r[1] << " " << r[2] << endl;
    cout << endl << stod("-0.7885") << endl;
    int *d = g.getTriangeFromLine("39//3456 7685//657 7688//575");
    cout << d[0] << " " << d[1] << " " << d[2] << "f" << endl;
    return 0;
}
