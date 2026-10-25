#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {
    int n;
    int k;

    // Einlesen der Anzahl der Elemente
    if (scanf("%d", &n) != 1) return 1;
    // Einlesen der gesuchten Position k
    if (scanf("%d", &k) != 1) return 1;
    
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    // Array-Elemente einlesen
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }
    
    // Quickselect aufrufen und das Ergebnis holen
    int result = quick_select(arr, 0, n - 1, k);
    
    // Nach den gesammelten Pivot-Ausgaben (die in quick_select ohne \n geschrieben wurden),
    // einen Zeilenumbruch setzen und das finale Ergebnis ausgeben.
    printf("\n%d\n", result);

    free(arr);
    return 0;
}