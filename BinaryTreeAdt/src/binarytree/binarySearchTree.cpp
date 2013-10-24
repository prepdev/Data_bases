/*
 * binarySearchTree.cpp
 *
 *  Created on: 2013-10-24
 *      Author: luqman
 */

#include "binarySearchTree.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

binarySearchTree::binarySearchTree() :  mp_root(NULL), m_size(0){
}

binarySearchTree::~binarySearchTree() {
	removeAllNodes();
}

void binarySearchTree::add(int  key, const char* value) {

	//Check for the length
	if ( strlen (value) >= VALUE_SIZE) {
		cout << endl <<"Value Size out of bound";
	}
	else {
		//create new node
		TreeNode* node = new TreeNode;
		if (node == NULL) {
			cerr << endl << "Unable to allocate memory for node";
			exit (-1);
		}
		node->key = key;
		strncpy (node->_value,value,strlen(value)+1);

		//Add node to the tree
		addNode(&mp_root,node);
	}
}

void binarySearchTree::remove(int key) {
	removeNode(&mp_root,key);
}

bool binarySearchTree::contains(int key) {
	return containsKey (mp_root,key);
}


bool binarySearchTree::containsKey (TreeNode *node, int key) {

	if (node == NULL) {
		return false;
	}
	else {
		if (key == node->key){
			return true;
		}
		else if (key <  node->key ) {
			containsKey(node->_left, key);
		}
		else if (key > node->key) {
			containsKey (node->_right,key);
		}
	}
}


bool binarySearchTree::getValueByKey(int key, char** value) {
	return getValueByTreeNode(mp_root,key,*value);
}

void binarySearchTree::removeAllNodes() {
	return removeAllTreeNodes(mp_root);
}

int binarySearchTree::getSize() const {
	return m_size;
}

int binarySearchTree::getDepth()  {
	return getTreeDepth(this->mp_root);
}

int binarySearchTree::getTreeDepth(TreeNode *root) {

	int depthLeftSubTree;
	int depthRightSubTree;

	//Case 1: Check if the tree is not empty
	if (root == NULL)
		return 0;
	else {
		depthLeftSubTree = getTreeDepth(root->_left);
		depthRightSubTree = getTreeDepth(root->_right);

		if (depthLeftSubTree > depthRightSubTree)
			return 1 + depthLeftSubTree;
		else
			return depthRightSubTree + 1;
	}
}

void binarySearchTree::removeAllTreeNodes(TreeNode* root) {
	if (root != NULL) {
		removeAllTreeNodes(root->_left);
		removeAllTreeNodes(root->_right);
		delete root;
	}
}

/*!
 * Adds the Node to the tree.
 * Binary Search Tree If the Key of new node is greater than root->key
 * then go the right branch, if less than root->key go to left.
 * Otherwise delete node. Keys should be unique in the tree
 */
void binarySearchTree::addNode(TreeNode** node, TreeNode* newNode) {

	//Case 1: Tree is empty. Base Condition for recursion
	if (*node == NULL) {
		*node = newNode;
		m_size++;
		return;
	}

	//Case 2: Key is less than node-key
	if (newNode->key < (*node)->key) {
		addNode(&((*node)->_left),newNode);
	}
	else if (newNode->key >  (*node)->key) {
		addNode(&((*node)->_right),newNode);
	}

	else {
		//Case 4: keys are equal delete the new node
		cout << endl <<"Root key and new Node key are equal deleting the node";
		delete newNode;
	}
}

void binarySearchTree::removeNode(TreeNode **root, int key) {

	//Case 1: If not empty
	if (*root != NULL) {
		//Search the node by Key
		if (key < (*root)->key) {
			//Go to the left branch to find the key
			removeNode(&((*root)->_left),key);
		}
		else if (key > (*root)->key) {
			//Go to right branch
			removeNode(&((*root)->_left),key);
		}
		else {
			//Found the Key. Recursive call to remove the root node
			removeRootNode((&(*root)),key);
		}
		m_size --;
	}
	else {
		cout << endl <<"Tree is empty";
	}
}

void binarySearchTree::removeRootNode(TreeNode** root, int key) {

	//Case 1: Node is a leaf
	if ((*root)->_left == NULL && (*root)->_right == NULL) {
		delete *root;
		*root = NULL;
	}

	//Create a temp TreeNode to delete
	TreeNode *temp;

	//Case 2: Node has a left child
	if ((*root)->_right == NULL) {
		temp = *root;
		*root = (*root)->_left;
		delete temp;
	}
	else if ((*root)->_left == NULL) {  //There is no right child
		temp = *root;
		*root = (*root)->_right;
		delete temp;
	}
	else { //Node has both right and left child.
		//Pass the root right and root.
		moveLeftMostNode(&((*root)->_right),*root);
	}

}

/*!
 * This method if the right node of root has left child if yes
 * then find the smallest in the left branch and replace the key and
 * value and delete the left node
 */
void binarySearchTree::moveLeftMostNode(TreeNode** node, TreeNode* root) {

	//Case 1: IF the Right of the root node do not have left child
	if ((*node) != NULL && (*node)->_left == NULL) {
		TreeNode *temp = *node; //this node will be deleted

		//Copy the right child k and v to the deleted node and remove right node
		root->key = (*node)->key;
		strcpy (root->_value,(*node)->_value);

		//shift the root node to the right
		*node = (*node)->_right;

		//delete the rigth node;
		delete temp;
	}

	//Case 2: The Right node of the deleted node has a left child
	// Now find the smallest in the left branch and replace the k,v to the deleted node
	// Delete the node which has the smallest k
	else {
		moveLeftMostNode(&((*node)->_left),root);
	}
}

void binarySearchTree::displayInOrder() {
	processTreeInOrder(mp_root);
}

bool binarySearchTree::getValueByTreeNode(TreeNode * node, int  key, char*& value) {

	if (node == NULL) {
		value[0] = '\0';
		return false;
	}
	else {
		if (node->key == key) {
			strcpy(value,node->_value);
			return true;
		}
		else if (key > node->key ) {
			getValueByTreeNode(node->_right,key,value);
		}
		else {
			getValueByTreeNode(node->_left,key,value);
		}
	}
}

void binarySearchTree::displayPreOrder() {
	processTreePreOrder(mp_root);
}

void binarySearchTree::displayPostOrder() {
	processTreePostOrder(mp_root);
}

void binarySearchTree::processTreeInOrder(TreeNode* node) {
	if (node != NULL) {
		processTreeInOrder(node->_left);
		cout << endl << "Key : " << node->key << " Value : " << node->_value;
		processTreeInOrder(node->_right);
	}
}

void binarySearchTree::processTreePreOrder(TreeNode* node) {
	if (node != NULL) {
		cout << endl << "Key : " << node->key << " Value : " << node->_value;
		processTreeInOrder(node->_left);
		processTreeInOrder(node->_right);
	}
}

void binarySearchTree::processTreePostOrder(TreeNode* node) {
	if (node != NULL) {
		processTreeInOrder(node->_left);
		processTreeInOrder(node->_right);

		cout << endl << "Key : " << node->key << " Value : " << node->_value;
	}
}







