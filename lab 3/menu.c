//
// Created by damib on 4/26/2025.
//
#include <stdio.h>
#include "menu.h"
#include "functions.h"

void show_menu() {
    treenode *root = NULL;
    int option, key;

    do {
        printf("\n=== BINARY TREE MENU ===\n");
        printf("1. read tree from input\n");
        printf("2. display tree (in-order)\n");
        printf("3. search node by value\n");
        printf("4. tree depth\n");
        printf("5. node depth\n");
        printf("6. node height\n");
        printf("7. display leaves\n");
        printf("8. free memory\n");
        printf("0. exit\n");
        printf("choose an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                if(root != NULL) {
                    printf("tree already loaded. freeing old memory...\n");
                    free_tree(root);
                }
                root = read_tree();
                break;
            case 2:
                if(root == NULL) printf("the tree is empty.\n");
                else {
                    printf("tree (in-order): ");
                    print_tree(root);
                    printf("\n");
                }
                break;
            case 3:
                printf("value to search for: ");
                scanf("%d", &key);
                if(search(root, key)) printf("node %d was found.\n", key);
                else printf("node %d was NOT found.\n", key);
                break;
            case 4:
                printf("tree depth: %d\n", depth(root));
                break;
            case 5:
                printf("node value: ");
                scanf("%d", &key);
                {
                    int d = node_depth(root, key, 0);
                    if(d != -1) printf("depth of node %d is %d\n", key, d);
                    else printf("node not found.\n");
                }
                break;
            case 6:
                printf("node value: ");
                scanf("%d", &key);
                {
                    treenode* node = search(root, key);
                    if(node != NULL) {
                        printf("height of node %d is %d\n", key, height(node));
                    } else {
                        printf("node not found.\n");
                    }
                }
                break;
            case 7:
                printf("tree leaves: ");
                print_leaves(root);
                printf("\n");
                break;
            case 8:
                free_tree(root);
                root = NULL;
                printf("memory has been freed.\n");
                break;
            case 0:
                printf("exiting...\n");
                free_tree(root);
                break;
            default:
                printf("invalid option. please try again.\n");
        }

    } while(option != 0);
}
