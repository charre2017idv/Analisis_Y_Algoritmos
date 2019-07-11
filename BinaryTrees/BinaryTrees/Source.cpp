/*
 * C++ Program To Implement BST
 */
#include "Header.h"
#include "CBinaryTrees.h"
/*
 * Main Contains Menu
 */
int main()
{
  int choice, num;
  CBinaryTrees bst;
  node *temp;
  while (1)
  {
    cout << "-----------------" << endl;
    cout << "Operations on Binary Trees" << endl;
    cout << "-----------------" << endl;
    cout << "1.Insert Element " << endl;
    cout << "2.Delete Element " << endl;
    cout << "3.Inorder" << endl;
    cout << "6.Display" << endl;
    cout << "7.Quit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      temp = new node;
      cout << "Enter the number to be inserted : ";
      cin >> temp->info;
      bst.insert(bst.root, temp);
      cout << endl;
    case 2:
      if (bst.root == NULL)
      {
        cout << "Tree is empty, nothing to delete" << endl;
        continue;
      }
      cout << "Enter the number to be deleted : ";
      cin >> num;
      bst.del(num);
      cout << endl;
      break;
    case 3:
      cout << "In-order Traversal of BST:" << endl;
      bst.inorder(bst.root);
      cout << endl;
      break;
    case 6:
      cout << "Display BST:" << endl;
      bst.display_Tree(bst.root, 1);
      cout << endl;
      break;
    case 7:
      exit(1);
    default:
      cout << "Wrong choice" << endl;
    }
  }
}
