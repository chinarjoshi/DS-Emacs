/* Defines the methods for the trie. Inherits the DataStructure_c class, so
 * polymorphism can be extensively used for all of the methods using a pointer
 * to the baes class.
 */

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "trie.h"

// inserts the key value pair into the trie. inserting approaches constant
// time as new nodes are inserted as less memory needs to be allocated to
// form a path
void Trie_c::Insert(const char *key, char const *word)
{
    int length = strlen(key);
    TrieNode_t *tmp = this->root;

    // each letter of the key is ocnverted to its corresponding index,
    // then inserted into the array of children node pointers. once the end
    // of the key is reached, the node is marked as the root and the value is
    // copied into the value field.
    for (int level = 0, index; level < length; level++)
    {
        index = GetIndex(key[level]);
        if (tmp->children[index] == nullptr)
            tmp->children[index] = GetNode();

        tmp = tmp->children[index];
    }
    tmp->end = true;
    strcpy(tmp->value, word);
}

// searches for the given key in the trie
char *Trie_c::Search(const char *key)
{
    int length = strlen(key);
    TrieNode_t *tmp = root;

    // very similar implementation as inserting, but once the end of the key is
    // reached, the node's value is returned
    for (int level = 0, index; level < length; level++)
    {
        index = GetIndex(key[level]);
        if (tmp->children[index] == nullptr)
            return "Not found";

        tmp = tmp->children[index];
    }
    return tmp->value;
}

// defines a recursive delete method that takes the root node, key, and depth
TrieNode_t *Trie_c::Delete(TrieNode_t *node, const char *word, int depth = 0)
{
    //checks to make sure there is something to delete
    if (node == nullptr)
        return nullptr;

    //recursive base case once the depth is equal to key length
    if (depth == strlen(word))
    {
      // if the node is marked as the end of the word, unmark it
        if (node->end)
            node->end = false;

        // if the node doesn't have children, it is safe to delete the node
        if (IsEmpty(node))
        {
            delete node;
            node = NULL;
        }
        return node;
    }

    // convert each letter to an index and check the if the node's children
    // has children of its own, otherwise it is safe to delete
    int index = word[depth] - 'a';
    node->children[index] = this->Delete(node->children[index], word, depth + 1);

    if (IsEmpty(node) && !node->end)
    {
        delete node;
        node = NULL;
    }

    return node;
}

// iterates though the trie and recurs itself on each of its children until a
// childless node is found, then deletes that node
void Trie_c::Unload(TrieNode_t *node)
{
    for (int i = 0; i < kAlphabetSize; i++)
        if (node->children[i] != NULL)
            this->Unload(node->children[i]);

    delete node;
}

void Trie_c::Export(std::ofstream &file, TrieNode_t *root, char word[], int depth)
{
    if (root->end)
    {
        word[depth] = '\0';
        file << word << std::endl;
    }

    for (int i = 0; i < kAlphabetSize; i++)
    {
        if(root->children[i])
        {
            word[depth] = i + 'a';
            Export(file, root->children[i], word, depth + 1);
        }
    }
}

// iterates over the node's children to check if it has any children
int Trie_c::IsEmpty(TrieNode_t *node) //const
{
    for (int i = 0; i < kAlphabetSize; i++)
        if (node->children[i] != nullptr)
            return false;

    return true;
}

// dynamically allocates a new TrieNode_t, and fills in its members with null
TrieNode_t *Trie_c::GetNode()
{
    TrieNode_t *newTrieNode = new TrieNode_t;
    if (newTrieNode != nullptr)
    {
        newTrieNode->end = false;
        for (int i = 0; i < kAlphabetSize; i++)
            newTrieNode->children[i] = NULL;
    }
    return newTrieNode;
}

// the root itself cannot be a virtual member of the base clsas, so a virtual
// method must be made to return the trie's root node
TrieNode_t *Trie_c::GetRoot()
{
    return root;
}

// constructor method allocates a new TrieNode_t for its root
Trie_c::Trie_c()
{
    this->root = new TrieNode_t;
}

// destructor method unloads the trie in case of a segfault
Trie_c::~Trie_c()
{
    this->Unload(this->root);
}
