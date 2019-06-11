#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} 

void print_array(int my_array[], int size) {
    int i = 0;
    
    for (i = 0; i < size; i ++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");
} 

void bubble_sort(int my_array[], int size) {
    int i = 0;
    int j = 0;
    
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1; j++) {
            if (my_array[j] > my_array[j + 1]) {
                swap(&my_array[j], &my_array[j + 1]);
            }
        }
    }
} 
