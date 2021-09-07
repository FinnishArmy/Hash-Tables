#include <stdlib.h>
#include <stddef.h>
#include<stdio.h>
#include "hashtable.h"

// Needed for memory allocation.
struct node * allocation(char *key, int frequency) {
    struct node *pointer = (struct node *) malloc(sizeof(struct node));

    if (pointer == NULL) {
      return pointer;
    }

    else if(pointer != NULL) {
      // Used for duplicating the string pointed by key while freeing the memory after you're done.
      // Source: https://www.geeksforgeeks.org/strdup-strdndup-functions-c/
        pointer->key = strdup(key);
      }

    return pointer;
}
