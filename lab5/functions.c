#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"


int* allocate_array(int number){
    return (int*)malloc(number * sizeof(int));
}

void free_array(int* arr){
    free(arr);
}

void initialize_array(int* arr, int number){
    srand(time(NULL));
    for(int i=0; i<number; i++){
        arr[i] = rand() % 100000;
    }
}

void print_array(const int* arr, int number){
    for(int i=0; i<number; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int* arr, int lenght){
    for(int i=0; i<lenght-1; i++){
        int min_idx = i;
        for(int j=i+1; j<lenght; j++){
            if(arr[j]<arr[min_idx])
                min_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void insertion_sort(int* arr, int number){
    for(int i=1; i<number; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bubble_sort(int* arr, int number){
    for(int i=0; i<number-1; i++){
        for(int j=0; j<number-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void merge(int* arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = allocate_array(n1);
    int* R = allocate_array(n2);

    for(int i=0; i<n1; i++) L[i] = arr[left + i];
    for(int j=0; j<n2; j++) R[j] = arr[mid + 1 + j];

    int i=0, j=0, k=left;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];

    free_array(L);
    free_array(R);
}

void merge_sort(int* arr, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int* arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    int temp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = temp;
    return i+1;
}

void quick_sort(int* arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}


void heapify(int* arr, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l<n && arr[l] > arr[largest]) largest = l;
    if(r<n && arr[r] > arr[largest]) largest = r;

    if(largest != i){
        int temp = arr[i]; arr[i] = arr[largest]; arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int* arr, int n){
    for(int i=n/2 -1; i>=0; i--)
        heapify(arr, n, i);

    for(int i=n-1; i>0; i--){
        int temp = arr[0]; arr[0] = arr[i]; arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int linear_search(const int* arr, int lenght, int target){
    for(int i=0; i<lenght; i++){
        if(arr[i] == target)
            return i;
    }
    return -1;
}

int binary_search(const int* arr, int lenght, int target){
    int left = 0, right = lenght-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid -1;
    }
    return -1;
}

uint64_t multiply(uint64_t F[2][2], uint64_t M[2][2]){
    uint64_t x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
    uint64_t y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
    uint64_t z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
    uint64_t w = F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
    return 0;
}

void power(uint64_t F[2][2], int n){
    if(n == 0 || n == 1) return;
    uint64_t M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F,F);

    if(n%2 != 0)
        multiply(F,M);
}

uint64_t fibonacci_fast(int number){
    if(number == 0) return 0;
    uint64_t F[2][2] = {{1,1},{1,0}};
    power(F, number-1);
    return F[0][0];
}
