//
//  Tree.cpp
//  lab6
//
//  Created by Anatoliy Khramchenko on 20.05.2021.
//

#include "Tree.hpp"

void Tree::addToNode(Triangle *newTriangle, Node *node) {
    node->area.addToArea(newTriangle);
    if (node->area.count == 1) {
        node->data = newTriangle;
    } else if (node->area.count == 2) {
        node->left = new Node;
        addToNode(node->data, node->left);
        node->right = new Node;
        addToNode(newTriangle, node->right);
        node->data = NULL;
    } else {
        if ((node->left->area.distToArea(newTriangle)) < (node->right->area.distToArea(newTriangle))) {
            addToNode(newTriangle, node->left);
        } else {
            addToNode(newTriangle, node->right);
        }
    }
}

void Tree::addToTree(Triangle *newTriangle) {
    addToNode(newTriangle, &root);
}

float Tree::findInTree(Ray ray) {
    float res = findInNode(ray, &root);
    if (res == -1) {
        return 0;
    } else {
        return res;
    }
}

float Tree::findInNode(Ray ray, Node *node) {
    float res = -1;
    if (node->area.count == 1) {
        if (node->data->isInTriangle(ray)) {
            return node->data->getColor();
        } else {
            return -1;
        }
    } else {
        if (node->left->area.isInArea(ray)) {
            res = findInNode(ray, node->left);
        }
        if (res != -1) {
            return res;
        }
        if (node->right->area.isInArea(ray)) {
            res = findInNode(ray, node->right);
        }
    }
    return res;
}
