#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void print_array(const int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]); 
    }
    printf("\n");
}

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int data[], int l, int r, int* compare_cnt) {
    int piv = data[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        (*compare_cnt)++;
        if (data[j] >= piv) {
            i++;
            swap(&data[i], &data[j]);
        }
    }
    i++;
    swap(&data[i], &data[r]);
    return i;
}

void quick_sort(int data[], int l, int r, int* compare_cnt) {
    if (l < r) {
        int m = partition(data, l, r, compare_cnt);
        printf("%d ", data[m]);
        quick_sort(data, l, m - 1, compare_cnt);
        quick_sort(data, m + 1, r, compare_cnt);
    }
}