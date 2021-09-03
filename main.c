#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

int main(int argc, char *argv[]) {

    FILE *fp;
    char *filename;
    hashtable *hash = createtable(50000);
    struct node *node = NULL;
    char word[100];
    int length = 0;

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
        if(fscanf(fp, "%s", word) != 1)
            break;
	length = strlen(word) - 1;
        if(ispunct(word[length]))
	    *(word + length) = '\0';
	if(strlen(word) > 0)
            node = add(hash, word, 1);
        node->frequency++;
    }
    fclose(fp);
    /* Print words with frequency higher than 250 */
    mostfrequent(hash, 250);
    freetable(hash);
    return 0;
}
