#include "BinaryTree.h"
#include <iostream>

using namespace std;

//**************************************************************
// insert accepts a TreeNode pointer and a pointer to a node.  *
// The function inserts the node into the tree pointed to by   *
// the TreeNode pointer. This function is called recursively.  *
//**************************************************************
void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
  if (nodePtr == nullptr)
    nodePtr = newNode; // Insert the node.
  else if (nodePtr->word.compare(newNode->word) > 0)
    insert(nodePtr->left, newNode); // Search the left branch.
  else
    insert(nodePtr->right, newNode); // Search the right branch.
}

//***********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function. *
//***********************************************************
void BinaryTree::insertNode(string word)
{
  TreeNode *newNode = nullptr;

  // Create a new node and store num in it.
  newNode = new TreeNode;
  newNode->word = word;
  newNode->used = 1;
  newNode->left = newNode->right = nullptr;

  // Insert the node.
  insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It *
// deletes all nodes in the tree. *
//***************************************************
void BinaryTree::destroySubTree(TreeNode *nodePtr)
{
  if (nodePtr)
  {
    if (nodePtr->left)
      destroySubTree(nodePtr->left);
    if (nodePtr->right)
      destroySubTree(nodePtr->right);
    delete nodePtr;
  }
}

//*******************************************************
// searchNode determines whether a value is present in *
// the tree. If so, the function returns true. *
// Otherwise, it returns false. *
//*******************************************************
bool BinaryTree::searchNode(string word)
{
  TreeNode *nodePtr = root;
  while (nodePtr)
  {
    if (nodePtr->word.compare(word) == 0)
      return true;
    else if (nodePtr->word.compare(word) > 0)
      nodePtr = nodePtr->left;
    else nodePtr = nodePtr->right;
  }
  return false;
}

//*******************************************************
// useNode determines whether a value is present in *
// the tree. If so, the function returns true and increase usage counter. *
// Otherwise, it returns false. *
//*******************************************************
bool BinaryTree::useNode(string word)
{
  TreeNode *nodePtr = root;
  while (nodePtr)
  {
    if (nodePtr->word.compare(word) == 0) {
      nodePtr->used++;
      return true;
    }
    else if (nodePtr->word.compare(word) > 0)
      nodePtr = nodePtr->left;
    else
      nodePtr = nodePtr->right;
  }
  return false;
}

//***********************************************
// remove calls deleteNode to delete the *
// node whose value member is the same as num. *
//***********************************************
void BinaryTree::remove(string word)
{
  deleteNode(word, root);
}

//********************************************
// deleteNode deletes the node whose value *
// member is the same as num. *
//********************************************
void BinaryTree::deleteNode(string word, TreeNode *&nodePtr)
{
  if (word.compare(nodePtr->word) > 0)
    deleteNode(word, nodePtr->left);
  else if (word.compare(nodePtr->word) > 0)
    deleteNode(word, nodePtr->right);
  else
    makeDeletion(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node *
// that is to be deleted. The node is removed and the *
// branches of the tree below the node are reattached. *
//***********************************************************
void BinaryTree::makeDeletion(TreeNode *&nodePtr)
{
  // Define a temporary pointer to use in reattaching
  // the left subtree.
  TreeNode *tempNodePtr = nullptr;

  if (nodePtr == nullptr)
    cout << "Cannot delete empty node.\n";
  else if (nodePtr->right == nullptr)
  {
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->left; // Reattach the left child.
    delete tempNodePtr;
  }
  else if (nodePtr->left == nullptr)
  {
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->right; // Reattach the right child.
    delete tempNodePtr;
  }
  // If the node has two children.
  else
  {
    // Move one node to the right.
    tempNodePtr = nodePtr->right;
    // Go to the end left node.
    while (tempNodePtr->left)
      tempNodePtr = tempNodePtr->left;
    // Reattach the left subtree.
    tempNodePtr->left = nodePtr->left;
    tempNodePtr = nodePtr;
    // Reattach the right subtree.
    nodePtr = nodePtr->right;
    delete tempNodePtr;
  }
}

//*************************************************************
// The displayInOrder member function displays the values *
// in the subtree pointed to by nodePtr, via inorder traversal. *
//*************************************************************
void BinaryTree::displayInOrder(TreeNode *nodePtr) const
{
  if (nodePtr)
  {
    displayInOrder(nodePtr->left);
    cout << nodePtr->word << " -> frequency: " << nodePtr->used << endl;
    displayInOrder(nodePtr->right);
  }
}
//*************************************************************
// The displayPreOrder member function displays the values *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//*************************************************************
void BinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
  if (nodePtr)
  {
    cout << nodePtr->word << " " << nodePtr->used << endl;
    displayPreOrder(nodePtr->left);
    displayPreOrder(nodePtr->right);
  }
}
//*************************************************************
// The displayPostOrder member function displays the values *
// in the subtree pointed to by nodePtr, via postorder traversal. *
//*************************************************************
void BinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
  if (nodePtr)
  {
    displayPostOrder(nodePtr->left);
    displayPostOrder(nodePtr->right);
    cout << nodePtr->word << " " << nodePtr->used << endl;
  }
}