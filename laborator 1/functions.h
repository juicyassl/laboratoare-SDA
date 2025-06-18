
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

Book *allocate_books_array(int size);

Book read_book();

void read_books(Book *book_array, int size);

void print_array(Book *book_array, int size);

void free_books_array(Book *book_array);

void sort_array(Book *book_array, int size);

void push_back(Book *book_array, int size, Book *new_book);

void push_front(Book *book_array, int size, Book *new_book);

void push_by_position(Book *book_array, int size, int position, Book *new_book);

void delete_by_position(Book *book_array, int size, int position);

void print_menu();

int read_option();

#endif //FUNCTIONS_H
