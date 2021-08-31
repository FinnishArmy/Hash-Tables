#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Main driver function.

// TODO: Make the main method take every word pairs.
int main (int argc, char *argv[]) {
  FILE *fp;
  char *filename;
  char ch;

  // Tell the user they forgot the file.
  if (argc < 2) {
    printf("Missing Filename\n");
    return(1);
  }
  // Print out the name of the file.
  else {
    filename = argv[1];
    printf("Filename : %s\n", filename);
  }

  fp = fopen(filename, "r");

  // Print the file contents.
  if (fp) {
    printf("File contents:\n");
    while ( (ch=fgetc(fp)) != EOF ) {
      printf("%c", ch);
    }
  }

  // Tell the user the file failed to open.
  else {
    printf("Failed to open the file\n");
  }
}
