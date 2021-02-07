/* Defines the methods for the Hashtable_c class. current methods include
 * inserting key value pairs, searching for a key, deleting a key value pair,
 * and unloading the data. the class inherits the 'initilaize' method from the
 * DataStructure_c class. Since its inherited and each datastructure has identical
 * method definitions, polymorphism can be extensively used to access the methods
 * abstracting the function away from the user.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>

#include "hash.h"

// dynamically allocates memory for a new HashNode_t and copies in the given
// key value pair into the corresponding fields in the class members, after the
// appropriate namespace is accessed
void HashTable_c::Insert(char const *key, char const *value)
{
    HashNode_t *n = new HashNode_t;
    if (n == nullptr)
        return;

    strcpy(n->value, value);
    strcpy(n->key, key);
    int hashValue = this->Hash(key);

    // this transfer of the linked list is crucial, the node pointer of the new node
    // points to the hashed value of the table, then the hashed table value points
    // to the new head. The order is important to preserve the pointers to the data.
    n->next = table[hashValue];
    table[hashValue] = n;
    count++;
}

// a temporary pointer points to the hashed key value of the table, and the
// pointer traverses the linked list comparing key to the node's key field
char *HashTable_c::Search(char const *key)
{
    HashNode_t *cursor = table[this->Hash(key)];
    while (cursor != nullptr)
    {
        if (!strcasecmp(cursor->key, key))
            return cursor->value;

        cursor = cursor->next;
    }
    return "Not found";
}

// the hash table uses an iterative solution while the trie uses a recursive
// solution, so the abstract class definition must fit to the most specific
// definition. Thus, the return value and attributes must be the same as the
// trie method so that polymorphism can be used.
TrieNode_t *HashTable_c::Delete(TrieNode_t *root, char const *key, int depth)
{
    HashNode_t *cursor = table[this->Hash(key)];
    HashNode_t *tmp = cursor;
    while (cursor)
    {
      // two traversal pointers are used until the value is found, then the next
      // value leapfrogs over the value to be deleted, then it is deleted
        if (strcasecmp(cursor->key, key))
        {
            tmp->next = cursor->next;
            delete cursor;
            return nullptr;
        }
        tmp = cursor;
        cursor = cursor->next;
    }
    return nullptr;
}

// iterates over the hash table array and traverses each linked list deleting the values.
void HashTable_c::Unload(TrieNode_t *node)
{
    for (int i = 0; i < kBuckets; i++)
    {
        HashNode_t *cursor = table[i];
        while (cursor != nullptr)
        {
            HashNode_t *tmp = cursor;
            cursor = cursor->next;
            delete tmp;
        }
    }
}

// prints all of the values of the hashtable to a file
void HashTable_c::Export(std::ofstream &file, TrieNode_t *root, char word[], int depth)
{
    for (int i = 0; i < kBuckets; i++)
    {
        HashNode_t *tmp = table[i];
        while (tmp)
        {
            file << tmp->key << tmp->value << std::endl;
            tmp = tmp->next;
        }
    }
}

// a non crypographic hash function that takes a string input and hashes the
// value to return an integer for the hash table
//adapted djb2 hash from http://www.cse.yorku.ca/~oz/hash.html
uint32_t HashTable_c::Hash(const char *word)
{
    uint32_t hash = 5381; int c;
    while ((c = toupper(*word++)))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % kBuckets;
}

// only present for the polymorphic function for the trie
TrieNode_t *HashTable_c::GetRoot()
{
    return nullptr;
}

// constructor method that simply sets the key count to 0
HashTable_c::HashTable_c()
{
    this->count = 0;
}

// destructor method that unloads the data in the case of segfault
HashTable_c::~HashTable_c()
{
    this->Unload(nullptr);
}
