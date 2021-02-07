/* since this header is included in every subsequent file, global enumerated
 * constants are defined here. The TrieNode_t class is also defined here in order
 * to keep consistent polymorphism with the pointer. DataStructure_c is an abstract
 * class that defines a shared initialize method and lays the framework for the
 * clsaes that inherit it.
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <iostream>
#include "trie.h"

typedef enum
{
    kMaxVal = 100,
    kMaxLen = 20,
    kAlphabetSize = 26,
    kMaxTokens = 5,
    kOptionsX = 8,
    kOptionsY = 2,
    kBuckets = 100,

} GlobalVals;

class DataStructure_c {
    public:
        void Initialize(char const *fname);
        virtual TrieNode_t *GetRoot() =0;
        virtual void Unload(TrieNode_t *node) =0;
        virtual void Insert(char const *key, char const *word) =0;
        virtual char *Search(const char *key) =0;
        virtual TrieNode_t *Delete(TrieNode_t *root, char const *key, int depth) =0;
        virtual void Export(std::ofstream& file, TrieNode_t *root, char word[], int depth) =0;
};

#endif
