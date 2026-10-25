#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    int compare_cnt = 0;
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    quick_sort(arr, 0, n - 1, &compare_cnt);
    printf("\n");

    print_array(arr, n);
    printf("Used %d comparisons.\n", compare_cnt);

    int a;
    scanf("%d", &a); 

    free(arr);
    return 0;
}