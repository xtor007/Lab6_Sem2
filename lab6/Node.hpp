//
//  Node.hpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Area.hpp"

class Node {
public:
    Area area;
    Triangle *data;
    Node *left = NULL;
    Node *right = NULL;
};

#endif /* Node_hpp */
