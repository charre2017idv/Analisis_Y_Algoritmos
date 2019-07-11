#include "CBinaryTrees.h"



CBinaryTrees::CBinaryTrees()
{
  root = NULL;
}


CBinaryTrees::~CBinaryTrees()
{
}

// Find Element in the Tree
void CBinaryTrees::find(int item, node **par, node **location)
{
  node *ptr, *ptrsave;
  if (root == NULL)
  {
    *location = NULL;
    *par = NULL;
    return;
  }
  if (item == root->info)
  {
    *location = root;
    *par = NULL;
    return;
  }
  if (item < root->info)
    ptr = root->left;
  else
    ptr = root->right;
  ptrsave = root;
  while (ptr != NULL)
  {
    if (item == ptr->info)
    {
      *location = ptr;
      *par = ptrsave;
      return;
    }
    ptrsave = ptr;
    if (item < ptr->info)
      ptr = ptr->left;
    else
      ptr = ptr->right;
  }
  *location = NULL;
  *par = ptrsave;
}

// Inserting Element into the Tree
void CBinaryTrees::insert(node *tree, node *newnode)
{
  if (root == NULL)
  {
    root = new node;
    root->info = newnode->info;
    root->left = NULL;
    root->right = NULL;
    cout << "Root Node is Added" << endl;
    return;
  }
  if (tree->info == newnode->info)
  {
    cout << "Element already in the tree" << endl;
    return;
  }
  if (tree->info > newnode->info)
  {
    if (tree->left != NULL)
    {
      insert(tree->left, newnode);
    }
    else
    {
      tree->left = newnode;
      (tree->left)->left = NULL;
      (tree->left)->right = NULL;
      cout << "Node Added To Left" << endl;
      return;
    }
  }
  else
  {
    if (tree->right != NULL)
    {
      insert(tree->right, newnode);
    }
    else
    {
      tree->right = newnode;
      (tree->right)->left = NULL;
      (tree->right)->right = NULL;
      cout << "Node Added To Right" << endl;
      return;
    }
  }
}

// Delete Element from the tree
void CBinaryTrees::del(int item)
{
  node *parent, *location;
  if (root == NULL)
  {
    cout << "Tree empty" << endl;
    return;
  }
  find(item, &parent, &location);
  if (location == NULL)
  {
    cout << "Item not present in tree" << endl;
    return;
  }
  if (location->left == NULL && location->right == NULL)
    case_a(parent, location);
  if (location->left != NULL && location->right == NULL)
    case_b(parent, location);
  if (location->left == NULL && location->right != NULL)
    case_b(parent, location);
  if (location->left != NULL && location->right != NULL)
    case_c(parent, location);
  free(location);
}

// Case A
void CBinaryTrees::case_a(node *par, node *loc)
{
  if (par == NULL)
  {
    root = NULL;
  }
  else
  {
    if (loc == par->left)
      par->left = NULL;
    else
      par->right = NULL;
  }
}

//Case B
void CBinaryTrees::case_b(node *par, node *loc)
{
  node *child;
  if (loc->left != NULL)
    child = loc->left;
  else
    child = loc->right;
  if (par == NULL)
  {
    root = child;
  }
  else
  {
    if (loc == par->left)
      par->left = child;
    else
      par->right = child;
  }
}

//Case C
void CBinaryTrees::case_c(node *par, node *loc)
{
  node *ptr, *ptrsave, *suc, *parsuc;
  ptrsave = loc;
  ptr = loc->right;
  while (ptr->left != NULL)
  {
    ptrsave = ptr;
    ptr = ptr->left;
  }
  suc = ptr;
  parsuc = ptrsave;
  if (suc->left == NULL && suc->right == NULL)
    case_a(parsuc, suc);
  else
    case_b(parsuc, suc);
  if (par == NULL)
  {
    root = suc;
  }
  else
  {
    if (loc == par->left)
      par->left = suc;
    else
      par->right = suc;
  }
  suc->left = loc->left;
  suc->right = loc->right;
}

//In Order Traversal
void CBinaryTrees::inorder(node *ptr)
{
  if (root == NULL)
  {
    cout << "Tree is empty" << endl;
    return;
  }
  if (ptr != NULL)
  {
    inorder(ptr->left);
    cout << ptr->info << "  ";
    inorder(ptr->right);
  }
}

// Display Tree Structure
void CBinaryTrees::display_Tree(node *ptr, int level)
{
  int i;
  if (ptr != NULL)
  {
    display_Tree(ptr->right, level + 1);
    cout << endl;
    if (ptr == root)
      cout << "Root->:  ";
    else
    {
      for (i = 0; i < level; i++)
        cout << "       ";
    }
    cout << ptr->info;
    display_Tree(ptr->left, level + 1);
  }
}