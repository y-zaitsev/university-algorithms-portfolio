#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

int partition(int data[], int l, int r);
int quick_select(int data[], int l, int r, int k);
void print_array(const int array[], int size);

#endif // UTILS_H