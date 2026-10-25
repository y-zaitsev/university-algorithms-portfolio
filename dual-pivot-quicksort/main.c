#include <stdio.h>
#include <stdlib.h>
#include "utils.h"  

int main() {
    
    int compare_cnt = 0; //  Anzahl der Vergleiche
    int n;

    // Anzahl der Elemente einlesen
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000) { //(1 ≤ n ≤ 1000)
        printf("Invalid input\n");
        return 1; 
    }

    // Dynamisches Array anlegen
    int *arr = malloc(n * sizeof(int));
    
    // Elemente einlesen
    for (int i = 0; i < n; i++) {
        
        if (scanf("%d", &arr[i]) != 1) { //wenn keine Zahl folgt Fehler
            printf("Invalid input \n");
            free(arr); // Speicher freigeben bei Fehler
            return 1;
        }
    }

    // Quicksort auf gesamtes Array anwenden
    quick_sort(arr, 0, n - 1, &compare_cnt);

    printf("\n"); // neue Zeile nach Pivot-Ausgaben

    //sortierte Array 
    print_array(arr, n);

    // Anzahl der Vergleiche ausgeben
    printf("Used %d comparisons.\n", compare_cnt);
    
    // Speicher freigeben
    free(arr);

    //nur damit der Terminal nicht schließt
    int a;
    scanf("%d", &a); 
    
    
    
    return 0; 
}