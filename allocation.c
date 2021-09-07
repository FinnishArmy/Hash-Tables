#include <stdlib.h>
#include <stddef.h>
#include<stdio.h>
#include "hashtable.h"

// Needed for memory allocation.
struct node * allocation(char *key, int frequency) {
    // Allocate memory for the node.
    struct node *pointer = (struct node *) malloc(sizeof(struct node));

    // If the pointer is already NULL, then simply return the pointer.
    if (pointer == NULL) {
      return pointer;
    }

    // If it's not NULL, then we want to duplicate the string pointer, then return that, instead.
    else if(pointer != NULL) {
      // Used for duplicating the string pointed by key while freeing the memory after you're done.
      // Source: https://www.geeksforgeeks.org/strdup-strdndup-functions-c/
        pointer->key = strdup(key);
      }
    // Just return the pointer, now.
    return pointer;
}
