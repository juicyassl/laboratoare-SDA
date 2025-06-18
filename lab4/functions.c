//
// Created by damib on 4/26/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

node* create_node(int key, const char* name, float value) {
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->key = key;
    new_node->name = name;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert_node(node* root, node* new_node) {
    if (root == NULL) return new_node;
    if (new_node->key < root->key)
        root->left = insert_node(root->left, new_node);
    else
        root->right = insert_node(root->right, new_node);
    return root;
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("key: %d, name: %s, value: %.2f\n", root->key, root->name, root->value);
        inorder(root->right);
    }
}

void preorder(node* root) {
    if (root != NULL) {
        printf("key: %d, name: %s, value: %.2f\n", root->key, root->name, root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("key: %d, name: %s, value: %.2f\n", root->key, root->name, root->value);
    }
}

node* search_node(node* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (key < root->key)
        return search_node(root->left, key);
    else
        return search_node(root->right, key);
}

void mirror_tree(node* root) {
    if (root != NULL) {
        node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror_tree(root->left);
        mirror_tree(root->right);
    }
}

void free_tree(node* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root->name);
        free(root);
    }
}

node** store_inorder(node* root, node** arr, int* index) {
    if (root != NULL) {
        arr = store_inorder(root->left, arr, index);
        arr[*index] = root;
        (*index)++;
        arr = store_inorder(root->right, arr, index);
    }
    return arr;
}

node* build_balanced_tree(node** arr, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    node* root = arr[mid];
    root->left = build_balanced_tree(arr, start, mid - 1);
    root->right = build_balanced_tree(arr, mid + 1, end);
    return root;
}

node* balance_tree(node* root) {
    int n = 0;
    node** arr = (node**)malloc(1000 * sizeof(node*));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    arr = store_inorder(root, arr, &n);
    root = build_balanced_tree(arr, 0, n - 1);
    free(arr);
    return root;
}
