//
// Created by damib on 4/10/2025.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

treenode *create_node(int data);

treenode *read_tree();

void print_tree(const treenode *root);

int depth(const treenode *root);

treenode *search(treenode *root, int key);

int node_depth(const treenode *root, int key, int depth);

int height(const treenode *node);

void print_leaves(const treenode *root);

void free_tree(treenode *root);

#endif //FUNCTIONS_H
