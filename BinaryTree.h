// Specification file for the IntBinaryTree class
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

using std::string;

class BinaryTree
{
private:
  struct TreeNode
  {
    int used;
    string word;
    TreeNode *left;
    TreeNode *right; // Pointer to right child node
  };
  TreeNode *root; // Pointer to the root node 16
  // Private member functions

  //**************************************************************
  // insert accepts a TreeNode pointer and a pointer to a node.  *
  // The function inserts the node into the tree pointed to by   *
  // the TreeNode pointer. This function is called recursively.  *
  //**************************************************************
  void insert(TreeNode *&, TreeNode *&);
  void destroySubTree(TreeNode *);
  void deleteNode(string, TreeNode *&);
  void makeDeletion(TreeNode *&);
  void displayInOrder(TreeNode *) const;
  void displayPreOrder(TreeNode *) const;
  void displayPostOrder(TreeNode *) const;

public:
  // Constructor
  BinaryTree()
  {
    root = nullptr;
  }
  // Destructor
  ~BinaryTree()
  {
    destroySubTree(root);
  }
  // Binary tree operations
  void insertNode(string);
  bool searchNode(string);
  bool useNode(string);
  void remove(string);

  void displayInOrder() const
  {
    displayInOrder(root);
  }
  void displayPreOrder() const
  {
    displayPreOrder(root);
  }
  void displayPostOrder() const
  {
    displayPostOrder(root);
  }
};
#endif