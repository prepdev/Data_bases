//============================================================================
// Name        : BinaryTreeAdt.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "binarytree/binarySearchTree.hpp"

using namespace std;

int main() {
	cout << endl << "Testing the Binary Search Tree ";

	int key;
	binarySearchTree tree;

	cout << endl << "Enter the Key (exit -999)";
	cin >> key;

	while (key != -999) {
		tree.add(key,"Luqman");
		cin >> key;
	}

	cout << endl << "========== Printing in Order ==========";
	tree.displayInOrder();


	cout << endl << "========== Printing in PreOrder ==========";
	tree.displayPreOrder();

	cout << endl << "========== Printing in PostOrder ==========";
	tree.displayPostOrder();

	return 0;
}
