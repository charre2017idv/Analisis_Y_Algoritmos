#pragma once
#include "Header.h"
struct node
{
  int info;
  struct node *left;
  struct node *right;
};
class CBinaryTrees
{
public:
  CBinaryTrees();
  ~CBinaryTrees();
public:
  node *root;
public:
  void 
  find(int, node **, node **);
  void 
  insert(node *, node *);
  void 
  del(int);
  void 
  case_a(node *, node *);
  void 
  case_b(node *, node *);
  void 
  case_c(node *, node *);
  void 
  inorder(node *);
  void 
  display_Tree(node *, int);
};

