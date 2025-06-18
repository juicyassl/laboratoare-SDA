
#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "functions.h"

void print_menu(){
    printf("\n--- menu ---\n");
    printf("1. initialize array with random numbers\n");
    printf("2. print array\n");
    printf("3. free array memory\n");
    printf("4. selection sort\n");
    printf("5. insertion sort\n");
    printf("6. bubble sort\n");
    printf("7. merge sort\n");
    printf("8. quick sort\n");
    printf("9. heap sort\n");
    printf("10. linear search\n");
    printf("11. binary search\n");
    printf("12. fibonacci number calculation\n");
    printf("0. exit\n");
    printf("choose option: ");
}

void display_menu(){
    int* arr = NULL;
    int n = 0;
    int option, target, index;
    clock_t start, end;
    double time_taken;

    while(1){
        print_menu();
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("enter array size: ");
                scanf("%d", &n);
                if(arr != NULL) free_array(arr);
                arr = allocate_array(n);
                initialize_array(arr, n);
                printf("array initialized\n");
                break;

            case 2:
                if(arr == NULL){
                    printf("array not initialized\n");
                } else {
                    print_array(arr, n);
                }
                break;

            case 3:
                if(arr != NULL){
                    free_array(arr);
                    arr = NULL;
                    n = 0;
                    printf("memory freed\n");
                } else {
                    printf("no memory allocated\n");
                }
                break;

            case 4:
                if(arr == NULL){
                    printf("array not initialized\n");
                    break;
                }
                start = clock();
                selection_sort(arr, n);
                end = clock();
                time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
                printf("selection sort done in %.6f seconds\n", time_taken);
                break;

            case 5:
                if(arr == NULL){
                    printf("array not initialized\n");
                    break;
                }
                start = clock();
                insertion_sort(arr, n);
                end = clock();
                time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
                printf("insertion sort done in %.6f seconds\n", time_taken);
                break;

            case 6:
                if(arr == NULL){
                    printf("array not initialized\n");
                    break;
                }
                start = clock();
                bubble_sort(arr, n);
                end = clock();
                time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
                printf("bubble sort done in %.6f seconds\n", time_taken);
                break;

            case 7:
                if(arr == NULL){
                    printf("array not initialized\n");
                    break;
                }
                start = clock();
                merge_sort(arr, 0, n-1);
                end = clock();
                time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
                printf("merge sort done in %.6f seconds\n", time_taken);
                break;

            case 8:
                if(arr == NULL){
                    printf("array not initialized\n");
                    break;
                }
                start = clock();
                quick_sort(arr, 0, n-1);
                end = clock();
                time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
                printf("quick sort done in %.6f seconds\n", time_taken);
                break;

            case 9:
                if(arr == NULL){
                    printf("array not initialized\n");
                    break;
                }
                start = clock();
                heap_sort(arr, n);
                end = clock();
                time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
                printf("heap sort done in %.6f seconds\n", time_taken);
                break;

            case 10:
                if(arr == NULL){
                    printf("array not initialized\n");
                    break;
                }
                printf("enter number to search: ");
                scanf("%d", &target);
                start = clock();
                index = linear_search(arr, n, target);
                end = clock();
                time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
                if(index != -1) printf("number found at index %d\n", index);
                else printf("number not found\n");
                printf("linear search took %.6f seconds\n", time_taken);
                break;

            case 11:
                if(arr == NULL){
                    printf("array not initialized\n");
                    break;
                }
                printf("array must be sorted for binary search\n");
                printf("enter number to search: ");
                scanf("%d", &target);
                start = clock();
                index = binary_search(arr, n, target);
                end = clock();
                time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
                if(index != -1) printf("number found at index %d\n", index);
                else printf("number not found\n");
                printf("binary search took %.6f seconds\n", time_taken);
                break;

            case 12:
                printf("enter fibonacci position n: ");
                scanf("%d", &n);
                if(n < 0){
                    printf("invalid position\n");
                    break;
                }
                uint64_t fibn = fibonacci_fast(n);
                printf("fibonacci(%d) = %llu\n", n, fibn);
                break;

            case 0:
                if(arr != NULL) free_array(arr);
                printf("exiting program\n");
                return;

            default:
                printf("invalid option\n");
        }
    }
}
#endif //MENU_H
