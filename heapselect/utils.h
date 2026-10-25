#ifndef UTILS_H
#define UTILS_H

typedef struct {
    int *array;
    int size;
    int capacity;
} MinHeap;

void init_heap(MinHeap *h);

void push_element(MinHeap *h, int value);

void build_heap(MinHeap *h);

int extract_top(MinHeap *h);

void free_heap(MinHeap *h);

#endif // UTILS_H