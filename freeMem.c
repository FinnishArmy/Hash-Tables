#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

void freetable(hashtable *h) {
    // Reset the nodes of the struct to NULL
    struct node *current = NULL;
    int i;
    // Walk through the hashtable, setting every node to NULL.
    for(i = 0; i < h->tablesize; i++) {
        current = h->table[i];
        // If the current node is already NULL, skip it.
        if(current == NULL)
            continue;
        // After setting them to NULL, free the memory.
        while(current->next != NULL) {
            h->table[i] = h->table[i]->next ;
            current = h->table[i];
        }
    }
    // Free the allocated memory of the whole hashtable.
    free(h->table);
    free(h);
}
