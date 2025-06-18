#include <stdio.h>
#include <stdlib.h>
#include "header.h"

vehicle *create_vehicle() {
    vehicle *new_vehicle = malloc(sizeof(vehicle));
    if (!new_vehicle) return NULL;
    return new_vehicle;
}

node *create_car_list(int num_of_cars) {
    node *head = NULL;
    node *current = NULL;
    for (int i = 0; i < num_of_cars; i++) {
        node *temp = malloc(sizeof(node));
        if (temp == NULL) {
            return NULL;
        }
        temp->Car = create_vehicle();
        if (temp->Car == NULL) {
            free(temp);
            return NULL;
        }
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            current = temp;
        } else {
            current->next = temp;
            current = temp;
        }
    }
    return head;
}

void enter_cars_data(node *head) {
    node *current = head;
    printf("Enter car data (year price brand model fuelType):\n");
    while (current != NULL) {
        scanf("%d %f %s %s %s", &current->Car->year, &current->Car->price,
              current->Car->brand, current->Car->model, current->Car->fuelType);
        current = current->next;
    }
}

void show_car_list(node *head) {
    node *current = head;
    int counter = 1;
    while (current != NULL) {
        printf("%d | year: %d, price: %.2f, brand: %s, model: %s, fuel: %s\n",
               counter, current->Car->year, current->Car->price,
               current->Car->brand, current->Car->model, current->Car->fuelType);
        current = current->next;
        counter++;
    }
}

void free_car_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp->Car);
        free(temp);
    }
}

int return_car_index(node *head, int chosen_field, int chosen_data) {
    node *current = head;
    int index = 0;
    while (current != NULL) {
        switch (chosen_field) {
            case 1:
                if (current->Car->year == chosen_data) {
                    return index;
                }
                break;
            case 2:
                if ((int)(current->Car->price) == chosen_data) {
                    return index;
                }
                break;
            default:
                printf("You entered a wrong field\n");
        }
        current = current->next;
        index++;
    }
    return -1;
}

int count_cars(node *head) {
    int count = 0;
    node *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void enter_car_data(node *new_node) {
    new_node->Car = create_vehicle();
    if (new_node->Car == NULL) {
        return;
    }
    printf("Enter car data (year price brand model fuelType): ");
    scanf("%d %f %s %s %s", &new_node->Car->year, &new_node->Car->price,
          new_node->Car->brand, new_node->Car->model, new_node->Car->fuelType);
}

void push_front(node **head) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) return;
    enter_car_data(new_node);
    new_node->next = *head;
    *head = new_node;
}

void push_back(node **head) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) return;
    enter_car_data(new_node);
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void insert_at_position(node **head, int position) {
    int count = count_cars(*head);
    if (position < 0 || position > count) return;
    if (position == 0) {
        push_front(head);
        return;
    }
    if (position == count) {
        push_back(head);
        return;
    }
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) return;
    enter_car_data(new_node);
    node *current = *head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

int check_list(const node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    return 0;
}

void pop_by_index(node **head, int index) {
    if (check_list(*head) == -1) return;
    node *temp = *head;
    if (index == 0) {
        *head = temp->next;
        free(temp->Car);
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) return;
    node *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete->Car);
    free(to_delete);
}

void invert_car_list(node **head) {
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void clean_list(node **head) {
    node *current = *head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp->Car);
        free(temp);
    }
    *head = NULL;
}
