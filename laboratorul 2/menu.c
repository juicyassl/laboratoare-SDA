// menu.c
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "header.h"

void print_menu_options() {
    printf("\n=== MAIN MENU ===\n");
    printf("%d. Exit program\n", EXIT);
    printf("%d. Print car list\n", PRINT_LIST);
    printf("%d. Return index of car\n", RETURN_INDEX);
    printf("%d. Sort list by field\n", SORT_BY_FIELD);
    printf("%d. Add car at beginning\n", PUSH_FRONT);
    printf("%d. Add car at end\n", PUSH_BACK);
    printf("%d. Insert car at position\n", INSERT_AT_POSITION);
    printf("%d. Remove car by index\n", POP_BY_INDEX);
    printf("%d. Invert list\n", INVERT_LIST);
    printf("%d. Clean list\n", CLEAN_LIST);
}

int read_option() {
    int option;
    printf("\nEnter an option: ");
    scanf("%d", &option);
    return option;
}

void show_menu(vehicle **cars) {
    do {
        print_menu_options();
        int option = read_option();

        switch (option) {
            case PRINT_LIST:
                show_car_list(*cars);
                break;

            case RETURN_INDEX: {
                printf("Choose field (1-year, 2-price): ");
                int field;
                scanf("%d", &field);
                printf("Enter search value: ");
                int value;
                scanf("%d", &value);
                int index = return_car_index(*cars, field, value);
                if (index != -1) {
                    printf("Found at index: %d\n", index);
                } else {
                    printf("Not found\n");
                }
                break;
            }

            case SORT_BY_FIELD: {
                printf("Choose field (1-price, 2-year): ");
                int field;
                scanf("%d", &field);
                printf("The sorted list is:\n");
                show_car_list(*cars);
                break;
            }

            case PUSH_FRONT:
                push_front(cars);
                break;

            case PUSH_BACK:
                push_back(cars);
                break;

            case INSERT_AT_POSITION: {
                printf("Enter position to insert at: ");
                int pos;
                scanf("%d", &pos);
                insert_at_position(cars, pos);
                break;
            }

            case POP_BY_INDEX: {
                printf("Enter index to remove: ");
                int index;
                scanf("%d", &index);
                pop_by_index(cars, index);
                break;
            }

            case INVERT_LIST:
                invert_car_list(cars);
                printf("List inverted\n");
                break;

            case CLEAN_LIST:
                clean_list(cars);
                printf("List cleaned\n");
                break;

            case EXIT:
                exit(0);

            default:
                printf("Invalid option\n");
        }
    } while (100);
}