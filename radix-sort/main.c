#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    size_t n;

    scanf("%zu", &n);

    unsigned int *a = malloc(n * sizeof(unsigned int));
    unsigned int *tmp = malloc(n * sizeof(unsigned int));

    if (!a || !tmp) {
        printf("Could not initialize Arrays!\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++)
        scanf("%u", &a[i]);

    radix_sort_bits(a, tmp, n);

    free(a);
    free(tmp);
    return 0;
}
