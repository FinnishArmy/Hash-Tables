#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Main program runner.
int main(int argc, char *argv[]) {

    // Arguments for getting the appropriate file.
    FILE *fp;
    char *filename;
    // Create the actual hashtable.
    hashtable *hash = createtable(1);
    // Set the node to NULL.
    struct node *node = NULL;
    // Max of 50 characters.
    char word[50];

    if (argc < 2) {
      printf("Missing filename\n");
      return(1);
    }

    else {
      filename = argv[1];
      printf(" Filename: %s\n ", filename);
    }

    fp = fopen(filename, "r");

    /* Load data from txt file to the hash table */
    while(1) {
        if(fscanf(fp, "%s", word) != 1) {
            break;
        }

        if(ispunct(word[strlen(word) -1])) {
	         *(word + strlen(word) - 1) = '\0';
         }

	      if(strlen(word) > 0) {
            node = add(hash, word, 1);
            node->frequency++;
        }
    }

    fclose(fp);
    frequencyCounter(hash);
}
