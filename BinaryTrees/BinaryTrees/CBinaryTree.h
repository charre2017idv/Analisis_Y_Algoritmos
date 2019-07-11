#pragma once

public:
  void find(int, node **, node **);
  void insert(node *, node *);
  void del(int);
  void case_a(node *, node *);
  void case_b(node *, node *);
  void case_c(node *, node *);
  void preorder(node *);
  void inorder(node *);
  void postorder(node *);
  void display(node *, int);
  BST()
  {
    root = NULL;
  }