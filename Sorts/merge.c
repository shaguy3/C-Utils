#include <stdio.h>

void print_array(int my_array[], int size) {
    int i = 0;
    
    for (i = 0; i < size; i ++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");
}

void merge(int my_array[], int left, int middle, int right) {
    int i = 0;
    int j = 0;
    int k = 0;

    int n1 = middle - left + 1;
    int n2 = right - middle;

    int left_array[n1];
    int right_array[n2]; //Creating two temporary arrays.
    
    for (i = 0; i < n1; i++) {
        left_array[i] = my_array[left + i];
    }
    for (j = 0; j < n2; j++) {
        right_array[j] = my_array[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (left_array[i] <= right_array[j]) {
            my_array[k] = left_array[i];
            i++;
        } else {
            my_array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        my_array[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2) {
        my_array[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int my_array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        merge_sort(my_array, left, middle);
        merge_sort(my_array, middle + 1, right);

        merge(my_array, left, middle, right);
    }
}
