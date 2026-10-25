#ifndef UTILS_H
#define UTILS_H


void quick_sort(int data[], int l, int r, int* compare_cnt);
void print_array(const int array[], int size);

int *partition(int data[], int l, int r, int *compare_cnt);

#endif 