#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int data[], int l, int r)
{
    int p = data[r];
    int i = l - 1;
    
    for (int j = l; j < r; j++) {
        if (data[j] >= p) {
            i++;
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i + 1], &data[r]);
    return i + 1;
}

int quick_select(int data[], int l, int r, int k)
{
    // Wenn nur noch ein Element übrig ist, wurde laut Beispiel 
    // keine Partitionierung mehr durchgeführt -> kein Pivot ausgeben.
    if (l == r) {
        return data[l];
    }

    if (l < r) {
        int m = partition(data, l, r);
        
        // Pivot nur ausgeben, wenn partitioniert wurde
        printf("%d ", data[m]);
        
        int left_len = m - l + 1;
        
        if (k == left_len) {
            return data[m];
        } else if (k < left_len) {
            return quick_select(data, l, m - 1, k);
        } else {
            return quick_select(data, m + 1, r, k - left_len);
        }
    }
    return -1;
}