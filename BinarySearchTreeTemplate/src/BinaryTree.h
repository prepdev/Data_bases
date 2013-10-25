/*
 * BinaryTree.h
 *
 *  Created on: 2013-10-25
 *      Author: luqman
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>

using namespace std;


template<class Type>
 struct Node {
	Type data;
	Node<Type> *right;
	Node<Type> *left;
};

template <class Type>
class BinaryTree {
public:
	BinaryTree();
	virtual ~BinaryTree();
	bool isEmpty() const;
	int getSize() const;
	int getHeight() const;
	BinaryTree(const BinaryTree<Type>& original);
	const BinaryTree<Type>& operator =(const BinaryTree<Type> &original);
	void destroyTree();
	bool contains(const Node<Type> & node);
	void add(const Type& item);
	void remove(const Type& item);
	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();

private:
	int getTreeHeight(const Node<Type> *root);
	void processInOrder(const Node<Type> * root);
	void processPostOrder(const Node<Type>* root);
	void processPreOrder(const Node<Type>* root);
	void destroyAllNodes(Node<Type> *root);
	void copyTree(Node<Type>** root, const Node<Type>* original);
	void removeNodeFromTree (Node<Type>** node);

protected:
	Node<Type> *mp_root;
	int m_size;
};

template<class Type>
inline BinaryTree<Type>::BinaryTree() :
		mp_root(NULL), m_size(0) {
}

template<class Type>
inline BinaryTree<Type>::~BinaryTree() {
	destroyTree();
}

template<class Type>
inline bool BinaryTree<Type>::isEmpty() const {
	return (mp_root == NULL);
}

template<class Type>
inline int BinaryTree<Type>::getSize() const {
	return m_size;
}

template<class Type>
inline int BinaryTree<Type>::getHeight() const {
	getTreeHeight(mp_root);
}

template<class Type>
inline BinaryTree<Type>::BinaryTree(const BinaryTree<Type>& original) {
	copyTree(&mp_root,original.mp_root);
}

template<class Type>
inline const BinaryTree<Type>& BinaryTree<Type>::operator =(
		const BinaryTree<Type>& original) {

	if (this != &original) {
		copyTree(&mp_root,original.mp_root);
	}
	return *this;
}

template<class Type>
inline void BinaryTree<Type>::destroyTree() {
	destroyAllNodes(mp_root);
}

template<class Type>
inline void BinaryTree<Type>::displayInOrder() {
	processInOrder(mp_root);
}

template<class Type>
inline void BinaryTree<Type>::displayPreOrder() {
	processPreOrder(mp_root);
}

template<class Type>
inline void BinaryTree<Type>::displayPostOrder() {
	processPostOrder(mp_root);
}

template<class Type>
inline int BinaryTree<Type>::getTreeHeight(const Node<Type> * root) {
}

template<class Type>
inline void BinaryTree<Type>::processInOrder(const Node<Type>* root) {
	if (root != NULL) {
		processInOrder(root->left);
		cout << endl << "Item -> " << root->data;
		processInOrder(root->right);
	}
}

template<class Type>
inline void BinaryTree<Type>::processPostOrder(const Node<Type>* root) {

	if (root != NULL) {
		processPostOrder(root->left);
		processPostOrder(root->right);
		cout << endl << "Item -> " << root->data;
	}
}

template<class Type>
inline void BinaryTree<Type>::processPreOrder(const Node<Type>* root) {
	if (root != NULL) {
		cout << endl << "Item -> " << root->data;
		processPreOrder(root->left);
		processPreOrder(root->right);
	}
}

template<class Type>
inline void BinaryTree<Type>::destroyAllNodes(Node<Type>* root) {
	if (root != NULL) {
		destroyAllNodes(root->left);
		destroyAllNodes(root->right);
		delete root;
	}
}

template<class Type>
inline void BinaryTree<Type>::copyTree(Node<Type>** root,
		const Node<Type> *otherRoot) {

	if (otherRoot == NULL) {
		root = NULL;
	} else {
		//Create the node of the tree
		*root = new Node<Type>;
		if (*root == NULL) {
			cout << endl << "Unable to allocate memory for the tree node";
			return;
		}
		(*root)->data = otherRoot->data;
		copyTree(&((*root)->left), otherRoot);
		copyTree(&((*root)->right), otherRoot);
	}
}

template<class Type>
inline bool BinaryTree<Type>::contains(const Node<Type>& node) {

	if (mp_root == NULL) {
		cerr << "The Tree is empty";
		return false;
	}
	bool found = false;
	Node<Type> *current = mp_root;
	while (current != NULL && !found) {
		if (node.data > current->data)
			current = current->right;

		else if (node.data < current->data)
			current = current->left;
		else
			found = true;
	}

	return found;
}

template<class Type>
inline void BinaryTree<Type>::add(const Type& item) {

	Node<Type>* newNode = new Node<Type>;
	if (newNode == NULL) {
		cerr << endl <<"Unable to allocate memory";
		return;
	}
	newNode->data = item;
	newNode->left = NULL;
	newNode->right = NULL;


	if (mp_root == NULL) {  //Tree is empty
		mp_root = newNode;
	}
	else {
		Node<Type> *current  = mp_root;
		Node<Type> *trailCurrent = NULL;

		while (current != NULL) {

			trailCurrent = current;
			if (current->data == item) {
				cout << endl <<"Can not add Duplicates";
				return;
			}

			else if (item > current->data)
				current = current->right;
			else
				current = current->left;
		}

		//Add the new node
		if (trailCurrent->data >  item)
			trailCurrent->left = newNode;
		else
			trailCurrent->right = newNode;
	}
}

template<class Type>
inline void BinaryTree<Type>::remove(const Type& item) {

	//Case 1: if root is not null
	if (mp_root == NULL) {
		cerr << endl <<"The Tree is empty";
	}
	else { //search the node with that item/data
		Node<Type> *current,*trailCurrent;
		trailCurrent = NULL;
		current = mp_root;
		if (current->data == item)  //Node to be deleted is the root
			removeNodeFromTree(&current);

		else {
			bool found = false;
			while ((current != NULL) & (!found)) {
				trailCurrent = current;
				if (item < current->data)
					current = current->left;
				else if (item > current->data)
					current = current->right;
				else
					found = true;
			}
			if (trailCurrent->data > current->data) {
				removeNodeFromTree(&trailCurrent->left);
			}
			else if (trailCurrent->data < current->data) {
				removeNodeFromTree(&trailCurrent->right);
			}
			else {
				cout << endl <<"Unable to find the item " << item;
			}
		}
	}






}

/*!
 * Case 1: If the node to be deleted do not have left or right
 * Case 2: If the node to be delete do not have left child
 * Case 3: If the node to be deleted do not have right child
 * Case 4: If the node has both right and left.
 *   Case 4.a Reduce to either Case 2 or Case 3.
 *   Case 4.b Reducing to Case 2 (No left child). Move to right and then find the leftmost child in the right of deleted node
 *   Case 4.c Reducing to Case 3 (No Right Child). MOve to left and the find the righmost leaf of left node.
 *   Case 4.d IF reducing to Case 4.c then once current is null terminate and replace the current to deleted node data if trail is not null
 *   		  then trail->right = current-> left Otherwise trail->left = current->right
 */
template<class Type>
inline void BinaryTree<Type>::removeNodeFromTree(Node<Type>** node) {

	Node<Type> *temp = NULL;

	//Case 1
	if ((*node)->left == NULL && (*node)->right) {
		delete *node;
		*node = NULL;
	}
	//Case 2
	else if ((*node)->left == NULL) {
		temp = *node;
		*node = (*node)->right;
		delete temp;
	}
	//Case 3
	else if ((*node)->right == NULL) {
		temp = *node;
		*node = (*node)->left;
		delete temp;
	}
	else {
		Node<Type> *trailCurrent, *current;
		trailCurrent = current = NULL;

		//Reducing to Case 2
		current = (*node)->left;

		while (current != NULL ) {
			trailCurrent = current;
			current = current->right;
		}

		//Here we have reached to the right most node
		(*node)->data = current->data;

		//Node to delete is the root node
		if (trailCurrent == NULL)
			(*node)->left = current->left;
		else
			trailCurrent->right = current->left;

		delete current;
	}
	m_size --;
}



#endif /* BINARYTREE_H_ */
