// defines the Trie_c class that inherits from DataStructure_c.

#ifndef TRIE_H
#define TRIE_H
#include <iosfwd>
#include <fstream>

// returns the size of an array based on length and size of the type
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
// converts a letter to an index
#define GetIndex(c) ((int)c - (int)'a')

#include "structures.h"

// since each node contains pointers to 26 other nodes, this datastructure
// exponentially grows in memory with new nodes
typedef struct TrieNode_t
{
    struct TrieNode_t *children[kAlphabetSize];
    bool end;
    char value[kMaxLen];
} TrieNode_t;

class Trie_c: public DataStructure_c {
    public:
        TrieNode_t *root;
        void Insert(const char *key, char const *word);
        char *Search(const char *key);
        TrieNode_t *Delete(TrieNode_t *node, const char *word, int depth);
        void Unload(TrieNode_t *node);
        void Export(std::ofstream &file, TrieNode_t *root, char word[], int depth);
        TrieNode_t *GetRoot();
        Trie_c();
        ~Trie_c();
    private:
        int IsEmpty(TrieNode_t *node);
        TrieNode_t *GetNode();
};

#endif
