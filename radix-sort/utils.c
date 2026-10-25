#include <stdio.h>
#include "utils.h"

static int highest_bit(unsigned int *a, size_t n) {
    if (n == 0) return 0;

    // Finde den größten Wert im Array, um das höchste Bit zu bestimmen
    unsigned int max_val = 0;
    for (size_t i = 0; i < n; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }
    
    int pos = 0;
    // Zähle die Bit-Verschiebungen, bis max_val 0 ist
    while (max_val > 0) {
        max_val >>= 1;
        pos++;
    }
    
    // Wenn pos > 0 ist, ist der höchste Index pos - 1 (0-basiert)
    return pos > 0 ? pos - 1 : 0;
}

void radix_sort_bits(unsigned int *a, unsigned int *tmp, size_t n) {
    if (n == 0) return;

    int max_bit = highest_bit(a, n);
    
    // Führe den RadixSort für jedes Bit vom LSB zum MSB durch
    for (int k = 0; k <= max_bit; k++) {
        size_t tmp_idx = 0;
        
        // 1. Durchlauf: Alle Elemente mit k-tem Bit == 0
        for (size_t i = 0; i < n; i++) {
            if (((a[i] >> k) & 1) == 0) {
                tmp[tmp_idx++] = a[i];
            }
        }
        
        // 2. Durchlauf: Alle Elemente mit k-tem Bit == 1
        for (size_t i = 0; i < n; i++) {
            if (((a[i] >> k) & 1) == 1) {
                tmp[tmp_idx++] = a[i];
            }
        }
        
        // Array zurückkopieren und den Zwischenschritt ausgeben
        for (size_t i = 0; i < n; i++) {
            a[i] = tmp[i];
            printf("%u ", a[i]);
        }
        printf("\n");
    }
}