
#include "functions.h"

#include <stdio.h>
#include <stdlib.h>

Book *allocate_books_array(int size) {
    Book *books = malloc(sizeof(Book) * size);
    if(books == NULL) {
        return NULL;
    }
    return books;
}

Book read_book(Book *book) {
    Book *book = malloc(sizeof(Book));
    printf("Enter book name: ");
    scanf("%s",book->title);
}

void read_books(Book *book_array, int size) {
    for (int i = 0; i < size; i++) {
        book_array[i] = read_book();
    }
}

void print_array(Book *book_array, int size) {
    printf("Books entered:\n");
    for (int i = 0; i < size; i++) {
        printf("%d| %s\n", i + 1, book_array[i].title);
    }
}
void free_books_array(Book *book_array) {
    free(book_array);
}