#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

// Initialisiert einen leeren Heap mit gegebener Startkapazität
void init_heap(MinHeap *h) {
    h->capacity = 4; // Speichergröße
    h->size = 0;
    h->array = (int*) malloc(h->capacity * sizeof(int));

    if (h->array == NULL) {
        fprintf(stderr, "Speicherallokierung fehlgeschlagen\n");
        exit(1);
    }
}
// Tauscht zwei Elemente im Array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Neues Element einfügen und Platz vergrößern, wenn nötig
void push_element(MinHeap *h, int value) {
    // Verdopple die Kapazität, wenn das Array voll ist
    if (h->size == h->capacity) {
        h->capacity *= 2;  // Neue Kapazität
        h->array = (int*) realloc(h->array, h->capacity * sizeof(int));
        if (h->array == NULL) {
            fprintf(stderr, "Speicherallokierung fehlgeschlagen\n");
            exit(1);
        }
    }
    // Neues Element am Ende des Arrays hinzufügen
    h->array[h->size++] = value;
}

// Stellt die Heap-Eigenschaft von oben nach unten wieder her
void heapify_down(MinHeap *h, int index) {
    int left = 2 * index + 1; // Index des linken Kindes
    int right = 2 * index + 2; // Index des rechten Kindes
    int target = index; // Index des kleinsten Elements


    // Die kleinste Zahl finden
    // Vergleiche mit linkem Kind
    if (left < h->size && h->array[left] < h->array[target]) {
        target = left;
    }

    // Vergleiche mit rechtem Kind
    if (right < h->size && h->array[right] < h->array[target]) {
        target = right;
    }

    // Wenn die Eltern nicht am kleinsten sind, tauschen
    if (target != index) {
        swap(&h->array[index], &h->array[target]);
        heapify_down(h, target); // Rekursiv weitermachen
    }
}

// Min-Heap von unten nach oben bauen (O(n))
void build_heap(MinHeap *h) {
    // Alle inneren Knoten von unten nach oben rebalancieren
    for (int i = h->size / 2 - 1; i >= 0; i--) {
        heapify_down(h, i);
    }
}

// Extrahiert und entfernt das oberste Element (Wurzel) aus dem Heap (O(log n)), hier die kleinste Zahl
int extract_top(MinHeap *h) {
    if (h->size == 0) {
        fprintf(stderr, "Heap ist leer\n");
        exit(1);
    }

    int top = h->array[0]; // Speichere die Wurzel
    h->array[0] = h->array[h->size - 1]; // Verschiebe letztes Element zur Wurzel
    h->size--; // Reduziere Größe
    
    heapify_down(h, 0);  // Stelle Heap-Eigenschaft wieder her
    
    return top; // Gib das oberste Element zurück
}

// Gibt den Speicher des Heaps frei
void free_heap(MinHeap *h) {
    free(h->array);
    h->array = NULL;  // Zeiger auf NULL setzen
}