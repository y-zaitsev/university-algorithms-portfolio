#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    int n;

    // Einlesen der Anzahl
    if (scanf("%d", &n) != 1) return 1;
    
    // Speicher reservieren
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    // Array-Werte einlesen
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Counting Sort aufrufen (dieser übernimmt auch die Ausgaben)
    counting_sort(arr, n);

    // Speicher freigeben
    free(arr);
    return 0;
}