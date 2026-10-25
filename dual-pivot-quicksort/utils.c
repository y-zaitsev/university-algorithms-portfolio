#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

// Gibt ein Array aus
void print_array(const int array[], int size)
{
    
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n"); 
}

// Partitioniert das Array in 3 Bereiche (Dual-Pivot)
int *partition(int data[], int l, int r, int *compare_cnt)
{
    (*compare_cnt)++; // Wir erhöhen den Zähler für den ersten Vergleich

    if (data[l] < data[r]) {
        int temp = data[l];
        data[l] = data[r];
        data[r] = temp;
    }
    
    // Zwei Pivots wählen
    int p1 = data[l]; // links
    int p2 = data[r]; // rechts

    
    int i = l + 1; // schiebt die großen Werte nach links
    int k = r - 1; // schiebt die kleinen Werte nach rechts
    int j = i;     // aktueller Index 

    // Durchlaufe das Array zwischen den Pivots
    while (j <= k) {
        (*compare_cnt)++; 
        // Fall 1: Element größer als linker Pivot
        if (data[j] > p1) {
            int temp = data[j];
            data[j] = data[i];
            data[i] = temp;
            i++;
            j++;
        } else {

            (*compare_cnt)++; 
            // Fall 2: Element kleiner als rechter Pivot
            if (data[j] < p2) {
                
                int temp = data[j];
                data[j] = data[k];
                data[k] = temp;
                k--; 
            } else {
                // Fall 3: Element liegt zwischen den Pivots
                j++;
            }
        }
    }

    // Pivots an ihre endgültigen Positionen setzen
    int temp = data[l];
    data[l] = data[i - 1];
    data[i - 1] = temp;

    // Positionen der Pivots zurückgeben
    temp = data[r];
    data[r] = data[k + 1];
    data[k + 1] = temp;

    
    // wir reservieren Speicher für ein Array mit 2 Zahlen und speichern dort die Positionen Pivots
    int *pivots = malloc(2 * sizeof(int));
    pivots[0] = i - 1; // Position Pivot 1
    pivots[1] = k + 1; // Position Pivot 2

    return pivots; // Wir geben das Array mit den zwei Positionen zurück
}

// Rekursive Dual-Pivot-Quicksort-Funktion
void quick_sort(int data[], int l, int r, int *compare_cnt)
{
    // Abbruch, Wenn l < r, gibt es mindestens zwei Elemente zu sortieren
    if (l < r) {
        // Wir teilen das Array und holen uns die zwei Pivot-Positionen
        int *pivots = partition(data, l, r, compare_cnt);
        int m1 = pivots[0]; // Position Pivot 1
        int m2 = pivots[1]; // Position Pivot 2

        // Speicher freigeben
        free(pivots);

        // Ausgabe der Pivot-Werte
        printf("%d %d ", data[m1], data[m2]);

        
        // Links (Zahlen größer als p1)
        quick_sort(data, l, m1 - 1, compare_cnt);
        // Mitte (Zahlen zwischen p1 und p2)
        quick_sort(data, m1 + 1, m2 - 1, compare_cnt);
        // Rechts (Zahlen kleiner als p2)
        quick_sort(data, m2 + 1, r, compare_cnt);
    }
}