#include <stdio.h>
#include "utils.h"

int main(void) {
    Heap max_heap, min_heap;
    
    // Startkapazität festlegen (wird bei Bedarf automatisch verdoppelt)
    init_heap(&max_heap, 4, true);  // Max-Heap (für die kleinere Hälfte der Zahlen)
    init_heap(&min_heap, 4, false); // Min-Heap (für die größere Hälfte der Zahlen)

    int num;
    
    //Liest Zahlen von der Eingabe (bis EOF = Ende der Datei)
    while (scanf("%d", &num) == 1) {
        add_number(&max_heap, &min_heap, num);
        
        // Gib den Median aus (immer die Wurzel des Max-Heaps)
        printf("%d\n", peek_top(&max_heap));
    }
    
    //Nur um das Programm nicht beendet
    int a;
    scanf("%d", &a); 
    
    // Speicher freigeben
    free_heap(&max_heap);
    free_heap(&min_heap);

    return 0;
}