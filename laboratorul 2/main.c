// main.c
#include "header.h"
#include "menu.h"
#include "struct.h"

int main() {
    int num_of_cars = 3;
    vehicle *cars = create_car_list(num_of_cars);
    enter_cars_data(cars);
    show_menu(&cars);
    free_car_list(cars);
    return 0;
}