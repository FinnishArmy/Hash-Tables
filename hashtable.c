#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    h->currentsize = h->currentsize + 1;
    return newnode;
}

// Returns the node pointer that matches the key.
struct node * getNode(hashtable *h, char *key) {
    // Uses the crc64 file to get the hashcode.
    int hash = crc64(key) % h->tablesize;
    struct node *current = h->table[hash];

    while(current != NULL) {
        if(strcmp(key, current->key) == 0) {
          return current;
        }
        else {
          current = current->next;
        }
    }
    return NULL;
}

// Prints out all of the word frequencies.
void mostfrequent(hashtable *h) {
    struct node *current = NULL;
    int i;
    for(i = 0; i < h->tablesize; i++) {
        current = h->table[i];
        while(current != NULL) {
            if(current->frequency > 0) {
                printf("        %d %-14s\n ", current->frequency, current->key);
            }
            current = current->next;
        }
    }
}

/* Returns a pointer to a newly allocated hash table */
struct hashtable * createtable(int size) {
    int i;
    if(size < 1){
      return NULL;
    }
    hashtable *table = (hashtable *) malloc(sizeof(hashtable));
    table->table = (struct node **) malloc(sizeof(struct node *) * size);

    if(table != NULL) {
        table->currentsize = 0;
        table->tablesize = size;
    }
    /* Set all pointers to NULL */
    for(i = 0; i < size; i++) {
      table ->table[i] = NULL;
    }
    return table;
}

/* Allocates memory for a new node. Initializes the new node's members */
struct node * allocation(char *key, int freq) {
    struct node *p = (struct node *) malloc(sizeof(struct node));

    if(p != NULL) {
        p->key = strdup(key);
        p->frequency = freq;
        p->next = NULL;
    }
    return p;
}

/* Deallocates memory of the string stored in the node and the
   node itself */
void freenode(struct node *node) {
    free(node->key);
    free(node);
}
