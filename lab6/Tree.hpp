//
//  Tree.hpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "Node.hpp"

class Tree {
    Node root;
    float findInNode(Ray ray, Node *node);
    void addToNode(Triangle *newTriangle, Node *node);
public:
    void addToTree(Triangle *newTriangle);
    float findInTree(Ray ray);
};

#endif /* Tree_hpp */
