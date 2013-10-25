//============================================================================
// Name        : BinarySearchTreeGeneric.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
	cout << "Binary Search Tree" << endl;

	BinaryTree<int> bst;
	cout << "Enter the item into tree (-999)";
	bst.add(45);
	bst.add(60);
	bst.add(80);
	bst.add(77);
	bst.add(75);
	bst.add(70);
	bst.add(48);
	bst.add(40);
	bst.add(32);
	bst.add(35);
	bst.add(30);
	bst.add(50);
	bst.add(53);
	bst.add(57);


	//cin >> item;
//
//	while (item != -999) {
//		bst.add(item);
//		cin >> item;
//	}

	cout << "=== Printing in order" << endl;
	bst.displayInOrder();
//	cout << " == Removing the item If no children " << endl;
//	bst.remove(45);
//	cout << " == Removing the item If no left " << endl;
//	bst.remove(30);
//	bst.displayInOrder();
//	cout << " == Removing the item If no right " << endl;
//	bst.remove(80);
//	bst.displayInOrder();
//	cout << " == Removing the item If has both children " << endl;
//	bst.remove(50);
//	bst.displayInOrder();

	return 0;
}
