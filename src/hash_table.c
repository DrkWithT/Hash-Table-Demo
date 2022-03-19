/**
 * @file hash_table.c
 * @summary: Implements my hash table.
 * @todo Make fill_count have some role in keeping track of the load factor (must be <50% ideally?). A load factor of about 50% should trigger a resize and rehash.
 */

#include "../headers/hash_table.h"

size_t createHash(const char* str, size_t table_size)
{
    size_t char_count = strlen(str);
    size_t key_id = 0;
    size_t hash_factor_pow = 1; // initially: it's 19^0
    size_t result_idx = 0;

    for(size_t iter = 0; iter < char_count; iter++)
    {
		// summation term: ASCII(some char) * (19 ^ i)
        key_id += (int)str[iter] * hash_factor_pow;

        hash_factor_pow *= HASH_FACTOR;
    }

    return key_id % HASH_TABLE_SIZE;
}

void HashTable_Init(HashTable* self)
{
    self->fill_count = 0;
    self->length = HASH_TABLE_SIZE;

    for(size_t i = 0; i < HASH_TABLE_SIZE; i++)
        self->values[i] = 0;
}

void HashTable_Clear(HashTable* self)
{
    for(size_t i = 0; i < HASH_TABLE_SIZE; i++)
        self->values[i] = 0;
    
    self->fill_count = 0;
	self->length = 0;
}

_Bool HashTable_setValue(HashTable* self, const char* key, int value)
{
    _Bool result = false;
    
    size_t value_index = createHash(key, HASH_TABLE_SIZE);

    // check for collision... succeeds when an empty slot is found OR setting fails on collision!
    result = self->values[value_index] == 0;
    
    if(result)
        self->values[value_index] = value;
    
    return result;
}

int HashTable_getValue(HashTable* self, const char* key)
{
    size_t result_idx = createHash(key, HASH_TABLE_SIZE);

    return self->values[result_idx];
}
