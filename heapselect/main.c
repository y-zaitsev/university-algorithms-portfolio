#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(void) {
    int k;
    // Erste Zahl k lesen
    if (scanf("%d", &k) != 1) {
        return 0; // Keine gültige Eingabe für k, Programm beenden
    }

    MinHeap heap;
    init_heap(&heap);

    int value;
    // Zahlen lesen, bis zum Ende (EOF - End Of File)
    while (scanf("%d", &value) == 1) {
        push_element(&heap, value);
    }

    if (k > 0 && k <= heap.size) {
        // Heap von unten nach oben bauen (O(n))
        build_heap(&heap);
        
        // Die k-1 kleinsten Zahlen entfernen
        for (int i = 0; i < k - 1; i++) {
            extract_top(&heap);
        }
        
        // Die k-te Zahl ausgeben
        printf("%d\n", extract_top(&heap));
    }

    // Warten auf Benutzereingabe
    int a;
    scanf("%d", &a);

    free_heap(&heap);
    return 0;
}