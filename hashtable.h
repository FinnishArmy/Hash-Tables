#include <stdbool.h>

// Create a node for the hashtable
struct node {
    char *key;
    int frequency;
    struct node *next;
};

// Create the hashtable
struct hashtable {
    struct node **table;
    int currentsize;
    int tablesize;
};

typedef struct hashtable hashtable;

// Function to add a new node to the hashtable
//    where it takes the parameters of the hashtable
//    the key's value and the actual value that
//    you want to store into the key. This then
//    returns the new node.
struct node *add(hashtable*, char*, int);

 // Function to print out the frequency of each word
 //   where it takes in the parameter of the just the hashtable.
 //   Uses a for loop to walk through the table.
void mostfrequent(hashtable*);


 // Function to initialize the hashtable and uses malloc to allocate
 //   memory for it. It uses the paramter int to determine the sizeof
 //   the array.
hashtable *createtable(int);
