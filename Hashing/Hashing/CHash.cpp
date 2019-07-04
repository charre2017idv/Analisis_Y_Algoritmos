#include "CHash.h"

CHash::CHash(int V)
{
  this->m_bucket = V;
  m_table = new list<int>[m_bucket];
}


CHash::~CHash()
{
}


void CHash::insertItem(int key)
{
  int index = hashFunction(key);
  m_table[index].push_back(key);
}

void CHash::deleteItem(int key)
{
  int index = hashFunction(key);                                                // get the hash index of key 
  list <int> ::iterator i;                                                      // find the key in indexed list 
  for (i = m_table[index].begin(); i != m_table[index].end(); i++) {
    if (*i == key)
      break;
  }
  if (i != m_table[index].end())                                                // if key is found in hash table, remove it 
    m_table[index].erase(i);
}

// function to display hash table 
void CHash::displayHash() {
  for (int i = 0; i < m_bucket; i++) {
    cout << i;
    for (auto x : m_table[i])
      cout << " -> " << x;
    cout << endl;
  }
}
