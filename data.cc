/* This program manipulates data with a fast compuational complexity using abstract
 * data structures such as a trie for O(1) lookup, search, and deletion, and
 * hash tables for O(n) lookup, search, and deletion but much more efficient
 * memory usage. Possible actions are to load a space delimited file into the
 * data structure indicated as a command line argument, and the user gives
 * vim inspired commands to manipulate the data. The program is highly extensible;
 * to add an algorithm, all the user must do is add the definition to the abstract
 * base class and child class to access it with the polymorphic object pointer.
 * The program makes extensive use of inheritance and polymorphism to make the
 * function as abstracted away from the user and reusable as possible.
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include "data.h"
#include "structures.h"
#include "hash.h"
#include "trie.h"

char currentFile[kMaxLen]; // contains the name of the current open file

// This object pointer uses polymorphism so that it doesn't matter which
// inherited class is used from the command line argument.
DataStructure_c *structure = NULL;

// takes user input and tokenizes it into an array of pointers
int main(void)
{
  char action[kMaxVal]; // contains the user's actions
  char *token[kMaxTokens]; //contains the tokenized user's actions
    PrintInstructions();
    while(1)
    {
        printf("(%s) ", currentFile);
        fgets(action, kMaxVal, stdin); // reads stdin to recieve command

        action[strcspn(action, "\n")] = 0; // removes the new line character from input

        // tokenizes the user input into the 'token' pointer array
        char *tmp = strtok(action, " ");
        for (int i = 0; tmp; i++)
        {
            token[i] = tmp;
            tmp = strtok(NULL, " ");
        }
        if (!ControlFlow(token)) // if the command is 'break', return 0
            return 0;
    }
}

// handles the control flow of the users commands. Accepts a char array of pointers
int ControlFlow(char *token[])
{
  switch(token[0][0])
  {
    case ':':
    {
      switch(token[0][1])
      {
        case 'e': // open and load file
        {   // uses pointer arithmetic to check if a second token is given
          if (*(&token + 1) - token == 3)
          {
          // if the second token is "hash", new hashtable
            structure = (!strcasecmp(token[2], "hash")) ?
                        (DataStructure_c*)(new HashTable_c) :
                        (DataStructure_c*)(new Trie_c);
          }
          else
          {
              // otherwise the object pointer points to a new trie
            structure = (DataStructure_c*)(new Trie_c);
          }
          // initialize the data strutrues with the indicated space-delimited file
          structure->Initialize(token[1]);
          printf("Opened %s\n", token[1]);
          strcpy(currentFile, token[1]);
          break;
        }

        case 'r': // remove
        {
          structure->Delete(structure->GetRoot(), token[1], 0);
          printf("Deleted %s\n", token[1]);
          break;
        }

        case 'i': // insert
        {
          structure->Insert(token[1], token[2]);
          printf("Inserted %s\n", token[1]);
          break;
        }

        case 's': // substitute
        {
          structure->Delete(structure->GetRoot(), token[1], 0);
          structure->Insert(token[1], token[2]);
          printf("Replaced %s with %s\n", token[1], token[2]);
          break;
        }

        case 'h': // help
        {
          PrintInstructions();
          break;
        }

        case 'w': // save to file
        {
          std::ofstream file(currentFile);
          char buffer[50];
          structure->Export(file, structure->GetRoot(), buffer, 0);

          if (token[0][2] != 'q')
          {
            break;
          }
        } // if ':wq', fall through to unload data

        case 'q': // unload data, ! to exit program
        {
          structure->Unload(structure->GetRoot());
          currentFile[0] = '\0';

          if (token[0][2] == '!')
          {
            return 0;
          }
          break;
        }

        default:
        {
          printf("Invalid Input.\n");
          break;
        }
      }
      break;
    }

    case '/': // search element
    {
      char *key = strtok(token[0], "/");
      printf("%s\n", structure->Search(key));
      break;
    }

    default:
    {
      printf("Invalid input.\n");
      break;
    }
  }
    return 1;
}

// prints the possible actions, add to this to extend program
void PrintInstructions(void)
{
    char astrisks[30];
    for(int i = 0; i < 30; i++) astrisks[i] = '*';
    printf("\n%s\nCOMMANDS:\n:e <file> (open file)\n/<key> (search)\n"
    ":insert <key value>\n:rm <key>\n:s <key value> (substitute)\n"
    ":help\n:w (save)\n:wq (save and close file)\n"
    ":q (close file)\n:q! (exit)\n%s\n", astrisks, astrisks);
}
