/* defines the HashNode_t structure and HashTable_c class.
 * the structure contains a pointer to the next node in the linked list, a buffer
 * for its corresponding key, and a buffer for the value. The class inherits the
 * DataStructure_c class and provides definitions for the abstract methods.
 */

#ifndef HASH_H
#define HASH_H

#include <stdint.h>
#include <fstream>
#include <iosfwd>
#include "structures.h"

typedef struct HashNode_t
{
    struct HashNode_t *next;
    char key[kMaxLen];
    char value[kMaxLen];
}
HashNode_t;

class HashTable_c: public DataStructure_c {
    public:
        void Insert(char const *key, char const *value);
        char *Search(char const *key);
        TrieNode_t *Delete(TrieNode_t *root, char const *key, int depth);
        TrieNode_t *GetRoot();
        void Unload(TrieNode_t *node);
        void Export(std::ofstream &file, TrieNode_t *root, char word[], int depth);
        HashTable_c();
        ~HashTable_c();
    private:
        uint32_t Hash(const char *word);
        HashNode_t *table[kBuckets];
        int count;
};

#endif
