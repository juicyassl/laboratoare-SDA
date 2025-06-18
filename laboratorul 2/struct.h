// struct.h
#ifndef STRUCT_H
#define STRUCT_H

typedef struct Car {
    int year;
    float price;
    char brand[50];
    char model[50];
    char fuelType[50];
} vehicle;

typedef struct node {
    vehicle *Car;
    struct node *next;
}node;

typedef struct linked_list {
    node* Head;
}linked_list;


enum Options {
    EXIT = 0,
    PRINT_LIST = 1,
    RETURN_INDEX = 2,
    SORT_BY_FIELD = 3,
    PUSH_FRONT = 4,
    PUSH_BACK = 5,
    INSERT_AT_POSITION = 6,
    POP_BY_INDEX = 7,
    INVERT_LIST = 8,
    CLEAN_LIST = 9
};

#endif //STRUCT_H