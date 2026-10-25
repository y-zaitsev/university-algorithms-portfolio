#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

// Initialisiert einen leeren Heap mit gegebener Startkapazität
void init_heap(Heap *h, int initial_capacity, bool is_max) {
    h->capacity = initial_capacity; // Speichergröße
    h->size = 0;
    h->array = (int*) malloc(h->capacity * sizeof(int));
    
    if (h->array == NULL) {
        fprintf(stderr, "Speicherallokierung fehlgeschlagen\n");
        exit(1);
    }
    h->is_max_heap = is_max;  // Heap-Typ
}

// Gibt den Speicher des Heaps frei
void free_heap(Heap *h) {
    free(h->array); 
    h->array = NULL;  // Zeiger auf NULL setzen
}

// Vergleicht zwei Werte entsprechend der Heap-Art (Max-Heap oder Min-Heap)
bool compare(Heap *h, int a, int b) {
    if (h->is_max_heap) {
        return a > b;  // Max-Heap: größere Werte haben Priorität
    } else {
        return a < b;  // Min-Heap: kleinere Werte haben Priorität
    }
}

// Tauscht zwei Elemente im Array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Stellt die Heap-Eigenschaft von unten nach oben wieder her
void heapify_up(Heap *h, int index) {
    if (index == 0) return;  // Wurzel erreicht, fertig
    
    int parent = (index - 1) / 2;  // Berechnet Index des Vater-Knotens
    
    if (compare(h, h->array[index], h->array[parent])) {
        swap(&h->array[index], &h->array[parent]);
        heapify_up(h, parent);  // Rekursiv weitermachen
    }
}

// Stellt die Heap-Eigenschaft von oben nach unten wieder her
void heapify_down(Heap *h, int index) {
    int left = 2 * index + 1; // Index des linken Kindes
    int right = 2 * index + 2; // Index des rechten Kindes
    int target = index; // Zielindex für den Tausch (initialisiert mit aktuellem Index)

    // Vergleiche mit linkem Kind
    if (left < h->size && compare(h, h->array[left], h->array[target])) {
        target = left;
    }
    
    // Vergleiche mit rechtem Kind
    if (right < h->size && compare(h, h->array[right], h->array[target])) {
        target = right;
    }

    // Wenn ein Kind eine höhere Priorität als der aktuelle Knoten hat, dann tauschen
    if (target != index) {
        swap(&h->array[index], &h->array[target]);
        heapify_down(h, target);  // Rekursiv weitermachen
    }
}

// Fügt ein Element in den Heap ein (O(log n))
void insert(Heap *h, int value) {
    //Verdopple die Kapazität, wenn das Array voll ist
    if (h->size == h->capacity) {
        h->capacity *= 2;  // Neue Kapazität
        h->array = (int*) realloc(h->array, h->capacity * sizeof(int)); 
        if (h->array == NULL) {
            fprintf(stderr, "Speicherallokierung fehlgeschlagen\n");
            exit(1);
        }
    }
    
    // Füge neues Element am Ende hinzu
    h->array[h->size] = value;
    
    // Stelle die Heap-Eigenschaft wieder her
    heapify_up(h, h->size);
    h->size++;  // Erhöhe die Anzahl der Elemente
}

// Extrahiert und entfernt das oberste Element (Wurzel) aus dem Heap (O(log n))
int extract_top(Heap *h) {
    if (h->size == 0) {
        fprintf(stderr, "Heap ist leer\n");
        exit(1);
    }
    
    int top = h->array[0]; // Speichere die Wurzel
    h->array[0] = h->array[h->size - 1]; // Verschiebe letztes Element zur Wurzel
    h->size--; // Reduziere Größe
    
    heapify_down(h, 0);  // Stelle Heap-Eigenschaft wieder her
    
    return top;  // Gib das oberste Element zurück
}

// Liest das oberste Element ohne es zu entfernen (O(1))
int peek_top(Heap *h) {
    if (h->size == 0) {
        fprintf(stderr, "Heap ist leer\n");
        exit(1);
    }
    return h->array[0];           // Gib die Wurzel zurück
}


// Fügt eine neue Zahl ein und hält die Balance zwischen den zwei Heaps
void add_number(Heap *max_heap, Heap *min_heap, int value) {
    //einfügen
    if (max_heap->size == 0 || value <= peek_top(max_heap)) {
        // Neue Zahl ist <= aktueller Median
        insert(max_heap, value); // Füge in Max-Heap ein
    } else {
        // Neue Zahl ist > aktueller Median
        insert(min_heap, value); // Füge in Min-Heap ein
    }

    //rebalancing
    if (max_heap->size > min_heap->size + 1) {
        // Max-Heap ist zu groß: verschiebe oberstes Element nach Min-Heap
        insert(min_heap, extract_top(max_heap));
    } else if (min_heap->size > max_heap->size) {
        // Min-Heap ist zu groß: verschiebe oberstes Element nach Max-Heap
        insert(max_heap, extract_top(min_heap));
    }
}