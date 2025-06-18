//
// Created by damib on 4/26/2025.
//
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "functions.h"

void show_menu() {
    binary_tree tree;
    tree.root = NULL;

    tree.root = insert_node(tree.root, create_node(50, "red", 100.0));
    tree.root = insert_node(tree.root, create_node(30, "blue", 90.5));
    tree.root = insert_node(tree.root, create_node(20, "green", 80.2));
    tree.root = insert_node(tree.root, create_node(40, "yellow", 95.3));
    tree.root = insert_node(tree.root, create_node(70, "purple", 110.7));
    tree.root = insert_node(tree.root, create_node(60, "orange", 105.1));
    tree.root = insert_node(tree.root, create_node(80, "black", 120.6));

    int option, key;
    char name[100];
    float value;

    do {
        printf("\n=== binary Search Tree Menu ===\n");
        printf("1. read node from keyboard\n");
        printf("2. display tree (in-order)\n");
        printf("3. search node by key\n");
        printf("4. traverse tree (in-order)\n");
        printf("5. traverse tree (pre-order)\n");
        printf("6. mirror tree\n");
        printf("7. clear tree\n");
        printf("8. free memory\n");
        printf("9. traverse tree (post-order)\n");
        printf("10.balance tree\n");
        printf("0. exit\n");
        printf("choose an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter name: ");
                scanf("%99s", name);
                printf("Enter value: ");
                scanf("%f", &value);
                tree.root = insert_node(tree.root, create_node(key, name, value));
                break;
            case 2:
            case 4:
                inorder(tree.root);
                break;
            case 3: {
                printf("Enter key to search: ");
                scanf("%d", &key);
                node* found = search_node(tree.root, key);
                if (found)
                    printf("Found node: Key: %d, Name: %s, Value: %.2f\n", found->key, found->name, found->value);
                else
                    printf("Node not found.\n");
                break;
            }
            case 5:
                preorder(tree.root);
                break;
            case 6:
                mirror_tree(tree.root);
                printf("Tree mirrored.\n");
                break;
            case 7:
            case 8:
                free_tree(tree.root);
                tree.root = NULL;
                printf("Tree cleared and memory freed.\n");
                break;
            case 9:
                postorder(tree.root);
                break;
            case 10:
                tree.root = balance_tree(tree.root);
                printf("Tree balanced.\n");
                break;
            case 0:
                free_tree(tree.root);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }

    } while (option != 0);
}