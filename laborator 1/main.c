#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "functions.h"


int main(void) {
    const int array_size = 10;

    Book *books = allocate_books_array(array_size);

    while (true) {
        print_menu();

        int option = read_option();

        switch (option) {
            case PRINT_ARRAY:
                break;
            case PUSH_BACK:
                break;
            default:
                break;
        }
    }

    return 0;
}
