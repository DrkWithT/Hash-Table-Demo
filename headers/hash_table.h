#ifndef HASH_TABLE_H
#define HASH_TABLE_H

/**
 * @file hash_table.h
 * @summary: This defines a string to int mapping within a static-sized hash table.
 * @version 0.1.1 Added more comments.
 * @todo Add linear probing and possibly a check if the statically sized HashTable is full!
 * @todo Add key checking and collision checking.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// temporary fixed size
#define HASH_TABLE_SIZE 16

// temporary shared hash factor for this fixed size implementation
#define HASH_FACTOR 31

/**
 * @fn createHash
 * @brief Generates a hashed index of the table's array for a string key...
 * Gets a string char by char, using sum of (ASCII * HASH_FACTOR power i) where i is the char's position.
 */
size_t createHash(const char* str, size_t table_size);

typedef struct hash_table
{
    size_t fill_count; // count of filled value slots within the table's array 
    size_t length; // length of table
    int values[HASH_TABLE_SIZE];
}HashTable;

/**
 * @fn HashTable_init()
 * @brief Defaults the internal array as zero values, and other data members to default values.
 * @param self The HashTable object. 
 */
void HashTable_Init(HashTable* self);

/**
 * @fn HashTable_Clear()
 * @brief .
 * @param self The HashTable object. 
 */
void HashTable_Clear(HashTable* self);

/**
 * @fn HashTable_setValue()
 * @param self The HashTable object.
 * @param key The HashTable's key string.
 * @param value The 32-bit integer value associated with its key string.
 * @returns Whether the operation succeeded or not.
 * @note See TODO!
 */
_Bool HashTable_setValue(HashTable* self, const char* key, int value);

/**
 * @fn HashTable_getValue()
 * @param self The HashTable object.
 * @param key The HashTable's key string.
 * @returns The 32-bit integer value associated with its key string.
 * @note Has no bounds checking yet.
 */
int HashTable_getValue(HashTable* self, const char* key);

#endif