/*
 * UnSortedLinkedList.cpp
 *
 *  Created on: 2013-10-21
 *      Author: luqman
 */

#include "UnSortedLinkedList.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

template<class Type>
UnSortedLinkedList<Type>::UnSortedLinkedList() :
		LinkedList<Type>() {
}
template<class Type>
UnSortedLinkedList<Type>::~UnSortedLinkedList() {
}

template<class Type>
void UnSortedLinkedList<Type>::insertFirst(const Type& data) {

	ListNode<Type>* newNode = new ListNode<Type>;
	if (newNode == NULL) {
		cerr << endl << "Unable to allocate memory for ListNode";
		exit(-1);
	}
	newNode->data = data;
	newNode->next = NULL;

	if (this->isEmpty()) {
		this->mp_first = newNode;
		this->mp_last = newNode;
	} else {
		newNode->next = this->mp_first;
		this->mp_first = newNode;
	}
	this->m_length++;
}

template<class Type>
void UnSortedLinkedList<Type>::insertLast(const Type& data) {
	ListNode<Type>* newNode = new ListNode<Type>;
	if (newNode == NULL) {
		cerr << endl << "Unable to allocate memory for ListNode";
		exit(-1);
	}
	newNode->data = data;
	newNode->next = NULL;

	if (this->isEmpty()) {
		this->mp_first = newNode;
		this->mp_last = newNode;
	}
	else {
		this->mp_last->next = newNode;
		this->mp_last = newNode;
	}
	this->m_length++;
}
