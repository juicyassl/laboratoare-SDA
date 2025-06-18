//
// Created by damib on 4/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


treenode *create_node(int data) {
    treenode* newNode = malloc(sizeof(treenode));
    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
treenode *read_tree() {
    int data;
    printf("enter the data for node (-1 for no node) ");
    scanf("%d", &data);
    if(data == -1) {
        return NULL;
    }
    treenode* node = create_node(data);

    printf("reading left child for %d\n", data);
    node->left = read_tree();

    printf("reading right child for %d\n", data);
    node->right = read_tree();
    return node;
}
void print_tree(const treenode *root) {
   if(root == NULL) {
       return;
   }
   printf("%d ", root->value);
   print_tree(root->right);
}
    int depth(const treenode *root) {
        if(root == NULL) return 0;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }

treenode* search(treenode *root, int key) {
    if(root == NULL) return NULL;
    if(root->value == key) return root;
    treenode* found = search(root->left, key);
    if(found != NULL) return found;
    return search(root->right, key);
}

int node_depth(const treenode *root, int key, int current_depth) {
    if(root == NULL) return -1;
    if(root->value == key) return current_depth;
    int left = node_depth(root->left, key, current_depth + 1);
    if(left != -1) return left;
    return node_depth(root->right, key, current_depth + 1);
}

int height(const treenode *node) {
    if(node == NULL) return -1;
    int left = height(node->left);
    int right = height(node->right);
    return (left > right ? left : right) + 1;
}

void print_leaves(const treenode *root) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        printf("%d ", root->value);
    }
    print_leaves(root->left);
    print_leaves(root->right);
}

void free_tree(treenode *root) {
    if(root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
