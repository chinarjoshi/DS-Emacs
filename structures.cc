#include <iostream>
#include <fstream>

#include "structures.h"

// defines the initalize method that is inherited by all datastructure clsses
// opnes the indicated file and reads key value pairs until eof. the insert
// method is derived from the class the object pointer points to.
void DataStructure_c::Initialize(char const *fname)
{
    std::ifstream infile(fname);

    char key[kMaxVal];
    char value[kMaxVal];
    while (infile >> key >> value)
    {
        this->Insert(key, value);
    }
}
