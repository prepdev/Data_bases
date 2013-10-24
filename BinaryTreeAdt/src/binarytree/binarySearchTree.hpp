/*
 * binarySearchTree.hpp
 *
 *  Created on: 2013-10-24
 *      Author: luqman
 */


#ifndef BINARYSEARCHTREE_HPP_
#define BINARYSEARCHTREE_HPP_

#include "BinaryNode.hpp"

/*!
 * Binary Search Tree is a binary tree with the following props
 * 1. The data stored at each node had a unique key and belongs to a total order e.g for any keys x,y x < y or x > y
 * 2. The key of any node is greater than all keys occuring in its left branch nodes. and less than all keys occuring on the right branch subtree
 *
 */

class binarySearchTree {
public:
	binarySearchTree();
	virtual ~binarySearchTree();
	void displayInOrder() const;
	void add (int key, const char *value);
	void remove (int key);
	bool contains (int key);
	bool getValueByKey(int key, char** value);
	void removeAllNodes();
	int getSize() const;
	int getDepth();
	void displayInOrder ();
	void displayPreOrder();
	void displayPostOrder();

private:
	int getTreeDepth(TreeNode *root);
	void removeAllTreeNodes (TreeNode *root);
	void addNode (TreeNode ** node, TreeNode * newNode);
	void removeNode (TreeNode **node, int key);
	void removeRootNode (TreeNode **root,int key);
	void moveLeftMostNode (TreeNode **node, TreeNode *root);
	bool containsKey (TreeNode *node, int key);
	bool getValueByTreeNode (TreeNode *node, int key, char* &value);
	void processTreeInOrder (TreeNode *node);
	void processTreePreOrder (TreeNode *node);
	void processTreePostOrder(TreeNode *node);

	TreeNode * mp_root;
	int m_size;
};

#endif /* BINARYSEARCHTREE_HPP_ */
