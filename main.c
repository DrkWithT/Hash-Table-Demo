#include <stdio.h>
#include "./headers/hash_table.h"

#define KEY_1 "foo"
#define KEY_2 "bar"
#define BAD_KEY "blah"

int main(void) {
    /// create HashTable for testing...
    HashTable table1;
    HashTable_Init(&table1);

    /// test hash table's setting function...
    if(HashTable_setValue(&table1, KEY_1, 42))
        puts("Insert 1 succeeded!");

    if(HashTable_setValue(&table1, KEY_2, 6))
        puts("Insert 2 succeeded!");

    // test hash table's value accessors...
    printf("table1[%s] = %i\n", KEY_1, HashTable_getValue(&table1, KEY_1)); // should be 42

    printf("table1[%s] = %i\n", KEY_2, HashTable_getValue(&table1, KEY_2)); // should be 6

    printf("table1[%s] = %i\n", BAD_KEY, HashTable_getValue(&table1, BAD_KEY)); // should be 0
    
    return 0;
}