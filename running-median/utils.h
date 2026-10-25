#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

typedef struct {
    int *array;
    int size;
    int capacity;
    bool is_max_heap;
} Heap;

void init_heap(Heap *h, int initial_capacity, bool is_max);

void free_heap(Heap *h);

void insert(Heap *h, int value);

int extract_top(Heap *h);

int peek_top(Heap *h);

void add_number(Heap *max_heap, Heap *min_heap, int value);

#endif // UTILS_H