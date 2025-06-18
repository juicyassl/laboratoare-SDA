// header.h
#ifndef HEADER_H
#define HEADER_H
#include "struct.h"

node *create_car_list(int num_of_cars);
void enter_cars_data(vehicle *head);
void show_car_list(vehicle *head);
void enter_car_data(vehicle *new_car);
int return_car_index(vehicle *head, int choosen_field, int choosen_data);
void free_car_list(vehicle *list_of_cars);
void push_front(vehicle **list_of_cars);
void push_back(vehicle **list_of_cars);
void insert_at_position(vehicle **list_of_cars, int position);
void pop_by_index(vehicle **list_of_cars, int index);
void invert_car_list(vehicle **list_of_cars);
void clean_list(vehicle **list_of_cars);
int count_cars(vehicle *head);

#endif //HEADER_H