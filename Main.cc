#include <iostream>

#include "BSTNode.h"
#include <string>

using namespace std;

int countNodes(BSTNode<string, int>*);
int countLeaves(BSTNode<string, int>*);
int countFullNodes(BSTNode<string, int>*);

int main()
{
  BSTNode<string, int> root; // root

  BSTNode<string, int> rlc; // root left child
  BSTNode<string, int> rrc; // root right child

  BSTNode<string, int> rllc; // root left left child
  BSTNode<string, int> rlrc; // root left right child

  BSTNode<string, int> rlllc; // root left left left child

  BSTNode<string, int> rrrc; // root right right child

  BSTNode<string, int> rrrrc; // root right right right child

  BSTNode<string, int> rrrlc; // root right right left child

  root.setLeft(&rlc);
  root.setRight(&rrc);

  rrc.setRight(&rrrc);
  rrc.setLeft(&rrrlc);
  rrrc.setRight(&rrrrc);

  rlc.setLeft(&rllc);
  rlc.setRight(&rlrc);

  rllc.setLeft(&rlllc);

  cout << "Nodes: " << countNodes(&root) << endl;
  cout << "Leaves: " << countLeaves(&root) << endl;
  cout << "Full Nodes: " << countFullNodes(&root) << endl;
}

int countLeaves(BSTNode<string, int>* root)
{
  if (root == NULL) {
    return 0;
  }
  if (root->isLeaf()) {
    return 1;
  } else {
    return countLeaves(root->left()) + countLeaves(root->right());
  }
}

int countFullNodes(BSTNode<string, int>* root)
{
  if (root == NULL || root->isLeaf()) {
    return 0;
  }
  if (root->isFull()) {
    return 1 + countFullNodes(root->left()) + countFullNodes(root->right());
  }
  if (root->left() != NULL && root->right() == NULL) {
    return countFullNodes(root->left());
  }
  if (root->left() == NULL && root->right() != NULL) {
    return countFullNodes(root->right());
  }

}

int countNodes(BSTNode<string, int>* root)
{
  if (root == NULL) {
    return 0;
  }
  return 1 + countNodes(root->left()) + countNodes(root->right());
}
