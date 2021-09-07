#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"
#include "crc64.h"

void freenode(struct node *);

// Adds a node to the hashtable using the key.
struct node *add(hashtable *h, char *key, int freq) {
    struct node *newnode;
    // Use the crc64 file to grab the hash-code.
    int hash = crc64(key) % h->tablesize;
    struct node *current = h->table[hash];

    // Search for duplicates
    while(current != NULL) {
        if(strcmp(key, current->key) == 0) {
          return current;
        }
        else {
          current = current->next;
        }
    }
   // After walking through with no duplicates, create a new node for the table.
    newnode = allocation(key, freq);
    newnode->next = h->table[hash];
    h->table[hash] = newnode;
}

// Prints out all of the word frequencies.
void mostfrequent(hashtable *h) {
    int i;
    struct node *current = NULL;
    for(i = 0; i < h->tablesize; i++) {
        current = h->table[i];
        while(current != NULL) {
            if(current->frequency > 0) {
                printf("        %d %s\n ", current->frequency+1, current->key);
            }
            current = current->next;
        }
    }
}

// Returns the pointer of the enw hashtable.
struct hashtable *createtable(int size) {
    hashtable *table = (hashtable*) malloc(sizeof(hashtable));
    table->table = (struct node**) malloc(sizeof(struct node*) *size);

    if(table != NULL) {
        table->tablesize = size;
    }
    return table;
}
