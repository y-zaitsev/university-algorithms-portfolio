#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int compare_ints(const void *a, const void *b) {
    int int_a = *(const int *)a;
    int int_b = *(const int *)b;
    return (int_a > int_b) - (int_a < int_b);
}

void print_array(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d\n", array[size-1]);
}

// Hilfsfunktion zur Berechnung der Fakultät, gedeckelt auf max int, um Überläufe zu vermeiden.
long long factorial(int n) {
    if (n <= 1) return 1;
    long long f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
        if (f > 2147483647LL) {
            // Wenn die Fakultät die Größe eines 32-Bit-Ints überschreitet,
            // können wir sie kappen. So bleibt i = (k-1)/f bei Werten k <= INT_MAX
            // sicher auf 0.
            return 2147483648LL; 
        }
    }
    return f;
}

void find(int* data, int length, int start, int k) {
    // Basisfall: Das Array hat nur noch ein Element zur Permutation übrig
    if (start >= length - 1) {
        return; 
    }
    
    int n_rem = length - start;
    long long f = factorial(n_rem - 1);
    
    // Position des neuen Start-Elementes innerhalb der restlichen Liste bestimmen
    int i = (k - 1) / f;
    int k_prime = k - (i * f);
    
    int target_index = start + i;
    int selected_value = data[target_index];
    
    // Array in-place nach rechts verschieben, um Platz an Index 'start' zu machen
    for (int j = target_index; j > start; j--) {
        data[j] = data[j - 1];
    }
    
    // Setze das ausgewählte Element an den Beginn der aktuellen Gruppe
    data[start] = selected_value;
    
    // Das Problem rekursiv auf die restlichen n-1 Elemente anwenden
    find(data, length, start + 1, k_prime);
}