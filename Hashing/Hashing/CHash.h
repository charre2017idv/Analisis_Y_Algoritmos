#pragma once
#include<iostream> 
#include <list> 
using namespace std;

class CHash
{
public:
  CHash(int V);
  ~CHash();


public:
  int m_bucket;                                                                 // No. of buckets 
  list<int> *m_table;                                                           // Pointer to an array containing buckets 
public:
  void 
  insertItem(int x);                                                            // Inserts a key into hash table 
  void 
  deleteItem(int key);                                                          // Deletes a key from hash table 
  int 
  hashFunction(int x) { return (x % m_bucket); }                                // Hash function to map values to key 
  void 
  displayHash();                                                                // Print Hash Table
};

