#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int main() {
    int n;
    // Anzahl der Elemente einlesen
    if (scanf("%d", &n) != 1) return 1;

    int *data = (int *)malloc(n * sizeof(int));
    if (data == NULL) return 1;

    // Array-Elemente einlesen
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    int k;
    // k einlesen
    if (scanf("%d", &k) != 1) {
        free(data);
        return 1;
    }

    // Array lexikographisch aufsteigend sortieren
    qsort(data, n, sizeof(int), compare_ints);

    // Initial sortiertes Array ausgeben
    print_array(data, n);
    
    // k-kleinste Permutation berechnen
    find(data, n, 0, k);

    // Ergebnis ausgeben
    printf("Die %d-kleinste Permutation ist:\n", k);
    print_array(data, n);

    free(data);

    int a;
    scanf("%d", &a); 
    
    return 0;
}