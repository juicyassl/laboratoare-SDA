//
// Created by damib on 4/26/2025.
//

#ifndef STRUCTS_H
#define STRUCTS_H


typedef struct node {
    int key;
    char *name;
    float value;
    struct node *left;
    struct node *right;
} node;

typedef struct binary_tree {
    node* root;
} binary_tree;

#endif //STRUCTS_H
