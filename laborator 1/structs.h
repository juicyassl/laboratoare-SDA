
#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Book {
    char title[50];
    char author[50];
    int pages_count;
} Book;

enum Options {
    EXIT = 0,
    PRINT_ARRAY = 1,
    PUSH_BACK = 2,

};

#endif //STRUCTS_H
