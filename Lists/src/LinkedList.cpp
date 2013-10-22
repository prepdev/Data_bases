//============================================================================
// Name        : LinkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include "LinkedList/ListNode.hpp"

using namespace std;

template <class Type>
void printList (ListNode<Type> *head) {
	ListNode<Type>* curr = head;
	while (curr != NULL) {
		cout <<endl <<"Item -> "<<curr->data;
		curr = curr->next;
	}
}
template <class Type>
void buildForwardList() {

	//Requires three pointers
	ListNode<Type> *newNode, *first, *last;
	newNode = first = last = NULL;
	int data;
	cout <<"\n Populate the list";
	cin>>data;

	while (data != -1) {
		newNode = new ListNode<Type>;
		newNode->data = data;
		newNode->next = NULL;

		if (!newNode) {
			cout <<endl <<"Unable to allocate memory for new node";
			exit(-1);
		}
		if (first == NULL) {
			first = newNode;
			last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
		cin>>data;
	}
	printList(first);
}
template <class Type>

void buildBackwardList() {

	ListNode<Type> *newNode, *first;
	newNode = first  = NULL;
	int data;
	cin >> data;
	while (data != -1) {
		newNode = new ListNode<Type>;
		newNode->data = data;
		newNode->next = first;
		first = newNode;
		cin>>data;
	}
	printList(first);
}


int main() {

	cout <<endl <<"Forward Linked List";
	//buildForwardList();
	cout <<endl <<"Backward Linked List";
	//buildBackwardList();

	return 0;
}
