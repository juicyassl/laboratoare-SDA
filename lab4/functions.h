//
// Created by damib on 4/26/2025.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structs.h"


node* create_node(int key, const char* name, float value);

node* insert_node(node* root, node* new_node);

void inorder(node* root);

void preorder(node* root);

void postorder(node* root);

node* search_node(node* root, int key);

void mirror_tree(node* root);

void free_tree(node* root);

node* balance_tree(node* root);


#endif //FUNCTIONS_H
