#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void print_array(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* count(int* data, int n, int min_value, int max_value) {
    // Größe des benötigten Zähl-Arrays bestimmen
    int range = max_value - min_value + 1;
    
    // Zähl-Array mit 0 initialisieren (calloc macht das automatisch)
    int* c = (int*)calloc(range, sizeof(int));
    if (c == NULL) return NULL;

    // Vorkommen der jeweiligen Werte zählen
    for (int i = 0; i < n; i++) {
        c[data[i] - min_value]++;
    }
    
    return c;
}

void counting_sort(int* data, int n) {
    if (n <= 0) return;

    // 1. Minimum und Maximum bestimmen
    int min_value = data[0];
    int max_value = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < min_value) min_value = data[i];
        if (data[i] > max_value) max_value = data[i];
    }

    // Ausgabe von min_value und max_value
    printf("%d %d\n", min_value, max_value);

    // 2. Frequenzen zählen lassen
    int* c = count(data, n, min_value, max_value);
    if (c == NULL) return;

    // Ausgabe des Array c
    int range = max_value - min_value + 1;
    print_array(c, range);

    // 3. Sortiertes Array generieren
    int index = 0;
    for (int i = 0; i < range; i++) {
        // Solange noch Vorkommen des Werts übrig sind
        while (c[i] > 0) {
            data[index] = i + min_value;
            index++;
            c[i]--;
        }
    }

    // 4. Ausgabe des sortierten Arrays
    print_array(data, n);

    // Hilfsarray freigeben
    free(c);
}