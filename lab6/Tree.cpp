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

float* Tree::findInTree(Ray ray) {
    float* res = findInNode(ray, &root);
    float *nulRes = new float[3];
    nulRes[0] = 0; nulRes[1] = 0; nulRes[2] = 0;
    if (res[0] == -1) {
        return nulRes;
    } else {
        return res;
    }
}

float* Tree::findInNode(Ray ray, Node *node) {
    float *res = new float[3];
    float *nulRes = new float[3];
    nulRes[0] = -1; nulRes[1] = -1; nulRes[2] = -1;
    res[0] = -1; res[1] = -1; res[2] = -1;
    if (node->area.count == 1) {
        if (node->data->intersect_triangle(ray)) {
            return node->data->getColor();
        } else {
            return nulRes;
        }
    } else {
        if (node->left->area.isInArea(ray)) {
            res = findInNode(ray, node->left);
        }
        if (res[0] != -1) {
            return res;
        }
        if (node->right->area.isInArea(ray)) {
            res = findInNode(ray, node->right);
        }
    }
    return res;
}
