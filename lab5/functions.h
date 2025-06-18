
#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdint.h>

/**
 * @brief dynamically allocates memory for an integer array
 *
 * @param number the number of elements to allocate
 * @return pointer to the allocated array
 */
int* allocate_array(int number);

/**
 * @brief frees the memory allocated for an integer array
 *
 * @param arr pointer to the array to be freed
 */
void free_array(int* arr);

/**
 * @brief fills the array with random integers in range [0, 999]
 *
 * @param arr pointer to the array to be filled
 * @param number the size of the array
 */
void initialize_array(int* arr, int number);

/**
 * @brief prints the contents of the array to the console
 *
 * @param arr pointer to the array to print
 * @param number the size of the array
 */
void print_array(int* arr, int number);

/**
 * @brief sorts the array using selection sort
 *
 * @param arr pointer to the array
 * @param number the size of the array
 */
void selection_sort(int* arr, int number);

/**
 * @brief sorts the array using insertion sort
 *
 * @param arr pointer to the array
 * @param number the size of the array
 */
void insertion_sort(int* arr, int number);

/**
 * @brief sorts the array using bubble sort
 *
 * @param arr pointer to the array
 * @param number the size of the array
 */
void bubble_sort(int* arr, int number);

/**
 * @brief sorts the array using merge sort algorithm
 *
 * @param arr pointer to the array
 * @param left the left index of the subarray
 * @param right the right index of the subarray
 */
void merge_sort(int* arr, int left, int right);

/**
 * @brief sorts the array using quick sort algorithm
 *
 * @param arr pointer to the array
 * @param low the starting index of the subarray
 * @param high the ending index of the subarray
 */
void quick_sort(int* arr, int low, int high);

/**
 * @brief sorts the array using heap sort algorithm
 *
 * @param arr pointer to the array
 * @param number the size of the array
 */
void heap_sort(int* arr, int number);

/**
 * @brief performs linear search on the array
 *
 * @param arr pointer to the array
 * @param number the size of the array
 * @param target the value to search for
 * @return the index of the found element or -1
 */
int linear_search(int* arr, int number, int target);

/**
 * @brief performs binary search on a sorted array
 *
 * @param arr pointer to the array
 * @param number the size of the array
 * @param target the value to search for
 * @return the index of the found element or -1
 */
int binary_search(int* arr, int number, int target);

/**
 * @brief calculates the nth fibonacci number efficiently using fast doubling
 *
 * @param number the position in the fibonacci sequence
 * @return the fibonacci number at the given position
 */
uint64_t fibonacci_fast(int number);

/**
 * @brief merges two sorted subarrays in merge sort
 *
 * @param arr pointer to the array
 * @param left starting index of the first subarray
 * @param mid ending index of the first subarray
 * @param right ending index of the second subarray
 */
void merge(int* arr, int left, int mid, int right);

/**
 * @brief partitions the array for quick sort
 *
 * @param arr pointer to the array
 * @param low starting index of the subarray
 * @param high ending index of the subarray
 * @return the partition index
 */
int partition(int* arr, int low, int high);

/**
 * @brief maintains the heap property in heap sort
 *
 * @param arr pointer to the array
 * @param number the size of the heap
 * @param i index of the current node
 */
void heapify(int* arr, int number, int i);


#endif //FUNCTION_H
