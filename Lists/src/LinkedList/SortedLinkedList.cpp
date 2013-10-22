/*
 * SortedLinkedList.cpp
 *s
 *  Created on: 2013-10-21s
 *      Author: luqman
 */

#include "SortedLinkedList.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

template<class Type>
void SortedLinkedList<Type>::insertFirst(const Type& data) {
	insert(data);
}

template<class Type>
void SortedLinkedList<Type>::insertLast(const Type& data) {
	insert(data);
}

template<class Type>
void SortedLinkedList<Type>::insert(const Type& data) {

	ListNode<Type>* newNode = new ListNode<Type>;
	if (newNode == NULL) {
		cerr <<endl <<"Unable to allocate memory";
		exit(-1);
	}
	newNode->data = data;
	newNode->next = NULL;

	//Case 1 if list is empty
	if (this->isEmpty()) {
		this->mp_first = newNode;
		this->mp_last = this->mp_first;
	}

	//Case 2 if added in the first location
	else if (this->mp_first->data >= data) {
		newNode->next = this->mp_first;
		this->mp_first = newNode;
	}
	//Case 3. Need to search for location
	else {
		bool found = false;

		ListNode<Type> * current = this->mp_first->next;
		ListNode<Type> *trailCurrent = this->mp_first;

		//Loop through the list
		while (current != NULL && !found) {
			if (current->data >= data) {
				found = true;
			}
			else {
				trailCurrent = current;
				current = current->next;
			}
		}

		//Case 3.a Need to add at the last

		trailCurrent->next = newNode;
		newNode->next = current;

		if (current == NULL) {
			this->mp_last = newNode;
		}

	}

	this->m_length++;
}
