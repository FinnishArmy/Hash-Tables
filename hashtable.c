#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"
#include "crc64.h"

// Adds a node to the hashtable using the key.
struct node *add(hashtable *word, char *key, int freq) {
    // Create a new node.
    struct node *newnode;
    // Use the crc64 file to grab the hash-code.
    int hash = crc64(key) % word->tablesize;
    // Use the cursor location and set the node to the word using the hashcode provided above.
    struct node *cursor = word->table[hash];

    // Search for duplicates
    while(cursor != NULL) {
        // Compare the string of the current location and see if the key is 0.
        if(strcmp(key, cursor->key) == 0) {
          // If the cursor is at 0, return the cursor.
          return cursor;
        }
        // otherwise, go to the next location.
        else {
          cursor = cursor->next;
        }
    }
   // After walking through with no duplicates, create a new node for the table.
   //   As well as, allocate memory for the node.
    newnode = allocation(key, freq);
    // Set the new node to the next word reading from the hashcode.
    newnode->next = word->table[hash];
    word->table[hash] = newnode;
}

// Prints out all of the word frequencies.
void mostfrequent(hashtable *word) {
    // Define a integer counter.
    int i;
    // Set the current location to NULL as we walk through printing the frequency.
    struct node *cursor = NULL;
    // Walk through the hashtable.
    for(i = 0; i < word->tablesize; i++) {
        // Set the cursor to the appropriate location.
        cursor = word->table[i];
        // As long as our cursor isn't NULL, that means we have more words to read.
        while(cursor != NULL) {
                // Then just print the frequency, and the word.
                printf("        %d %s\n ", cursor->frequency+1, cursor->key);
            // Then set the cursor to the next word and re-do it for the next word...
            cursor = cursor->next;
        }
    }
}

// Returns the pointer of the new hashtable.
struct hashtable *createtable(int size) {
    // Allocation memory for the table.
    hashtable *table = (hashtable*) malloc(sizeof(hashtable));
    // Allocation memory for the struct.
    table->table = (struct node**) malloc(sizeof(struct node*) *size);

    // If the table isn't NULL, then set the size of the table.
    if(table != NULL) {
        table->tablesize = size;
    }
    // Return the new hashtable.
    return table;
}
