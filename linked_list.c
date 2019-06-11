#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node *next;
};

void die(char *message);
void append(struct node *list, int num_to_insert);
void insert_at_beginning(struct node **list, int num_to_insert);
int get_number(struct node *list, int index);
void print_list(struct node *list);

int main() {
    struct node *my_list = malloc(sizeof(struct node));
    my_list->number = 6;
    
    append(my_list, 7);
    insert_at_beginning(&my_list, 14);
    append(my_list, 2);

    int second_number = get_number(my_list, 1);
    printf("The second number in the list is %d.\n", second_number);

    print_list(my_list);
    printf("\n");

    free(my_list);    

    return 0;
}

void die(char *message) {
    printf("ERROR: %s\n", message);
    exit(1);
}

void append(struct node *list, int num_to_insert) {
    printf("Inserting the number %d to the end of the list.\n", num_to_insert);
    struct node *current = list;
    if (current == NULL) {
        die("Cannot append a number to an unallocated list.");
    }

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct node));
    current->next->number = num_to_insert;
}

void insert_at_beginning(struct node **list, int num_to_insert) {
    printf("Inserting the number %d to the start of the list.\n", num_to_insert);
    if (*list == NULL) {
        die("Cannot add a number to the beginning of an unallocated list.");
    }

    struct node *new_first = malloc(sizeof(struct node));
    new_first->number = num_to_insert;

    new_first->next = *list;
    *list = new_first;
}

int get_number(struct node *list, int index) {
    if (list == NULL) {
        die("Cannot get a number from an unallocated list.");
    }

    struct node *current = list;
    int counter = 0;
    while (counter <= index) {
        if (counter == index) {
           return current->number;
        }
        
        if (current->next == NULL) {
           die("Can't find the requested index in the list.");
        }
        
        current = current->next;
        counter++;
    }   
    return 0;
}

void print_list(struct node *list) {
    struct node *current = list;
    if (current == NULL) {
        die("Cannot print an empty list.");
    }

    while(current->next != NULL) {
        printf("%d ", current->number);
        current = current->next;
    }

    printf("%d", current->number);
}
