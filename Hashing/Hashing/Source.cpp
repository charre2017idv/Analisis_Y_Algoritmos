//------------------------------------------------------------------------------
// File: main.cpp
// Version: v 4.0
// Author: Roberto Charreton Kaplun
// Summary: 
// Errors: 
// Bugs: 
// Nice to Have: 
//------------------------------------------------------------------------------
#include "CHash.h"
int Array[] = 
{
  15, 11, 27,  8, 12,
  12,  5, 56, 23, 26,
  68,  9, 76, 12,  5,
  56, 23, 26, 68,  9,
  76,  1, 23, 45,  5
};

int main()
{
  int size = sizeof(Array) / sizeof(Array[0]);
  int n = 5;
  CHash HashTable(n);                                                           // insert the keys into the hash table 
  for (int i = 0; i < size; i++)
    HashTable.insertItem(Array[i]);

 // HashTable.deleteItem(1);                                                      // delete value from hash table 
  HashTable.displayHash();                                                      // display the Hash table 
  cin.get();
  cin.ignore();
  return 0;
}
