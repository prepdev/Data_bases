/*
 * LinkedList.cpp
 *
 *  Created on: 2013-10-21
 *      Author: luqman
 */

#include "LinkedList.hpp"
#include <iostream>

using namespace std;

template<class Type>
LinkedList<Type>::LinkedList() : mp_first(0),mp_last(0),m_length(0) {
}

template<class Type>
LinkedList<Type>::~LinkedList() {
}

template<class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& original) {
	makeCopy(original);
}

template<class Type>
 const LinkedList<Type>& LinkedList<Type>::operator =(
		const LinkedList<Type>& original) {

	if (this != &original) {
		makeCopy(original);
	}
	return *this;
}

template<class Type>
 void LinkedList<Type>::initializeList() {
	destroyList();
}

template<class Type>
void LinkedList<Type>::destroyList() {
	if (!isEmpty()) {
		ListNode<Type> *temp = NULL;

		while (mp_first != NULL) {
			temp = mp_first;
			mp_first = mp_first->next;
			delete temp;
		}
		mp_last = 0;
		m_length = 0;
	}
	else {
		cout <<endl <<"List is Empty";
	}
}

template<class Type>
void LinkedList<Type>::printList() const {
	if (!isEmpty()) {
		ListNode<Type> *temp = mp_first;
		while (temp != NULL) {
			cout <<endl << temp->data;
			temp = temp->next;
		}
	}
	else {
		cout <<endl <<"List is Empty";
	}
}

template<class Type>
Type LinkedList<Type>::getFirst() const {
	if (!isEmpty()) {
		return mp_first->data;
	}
}

template<class Type>
 Type LinkedList<Type>::getLast() const {
	if (!isEmpty()) {
			return mp_last->data;
	}
}

template<class Type>
bool LinkedList<Type>::isEmpty() const {
	return (mp_first == 0);
}

template<class Type>
inline int LinkedList<Type>::getLength() const {
	return m_length;
}

template<class Type>
LinkedListIter<Type> LinkedList<Type>::begin() {
	LinkedListIter<Type> iter(mp_first);
	return iter;
}

template<class Type>
 LinkedListIter<Type> LinkedList<Type>::end() {
	LinkedListIter<Type> iter(0);
	return iter;
}

template<class Type>
void LinkedList<Type>::makeCopy(
		const LinkedList<Type>& original) {

	if (mp_first != NULL)
		destroyList();

	if (original.mp_first == NULL ) {
		mp_first = NULL;
		mp_last = NULL;
		m_length = 0;
	}
	else {
		m_length = original.m_length;
		ListNode<Type> * current = original.mp_first;
		ListNode<Type> * newNode = NULL;

		//Create the first node
		mp_first = new ListNode<Type>;
		mp_first->data = current->data;
		mp_first->next = NULL;

		mp_last = mp_first;
		//Move the current pointer to next node
		current = current->next;
		while (current != NULL) {
			newNode = new ListNode<Type>;
			newNode->data = current->data;
			newNode->next = NULL;
			mp_last->next = newNode;
			mp_last = newNode;
			current = current->next;
		}
	}
}

template<class Type>
void LinkedList<Type>::deleteNode(const Type& data) {

	ListNode<Type> *current, *trailCurrent;
	current = trailCurrent = NULL;

	if (this->mp_first == NULL) {
		cout << endl <<"List is empty";
	}
	else if (this->mp_first->data == data) {
		current = this->mp_first;
		this->mp_first = this->mp_first->next;
		delete current;
		this->m_length--;
	}
	else {
		trailCurrent = this->mp_first; //first item
		current = this->mp_first->next; //second item
		bool found = false;

		while (current != NULL && !found) {
			if (current->data != data) {
				trailCurrent = current;
				current = current->next;
			}
			else {
				found = true;
				break;
			}
		}

		if (found) {
			trailCurrent->next = current->next;
			this->m_length--;
			if (current == this->mp_last) {
				this->mp_last = trailCurrent;
			}
			delete current;
		}
		else {
			cout <<endl <<"Item is not in the List";
		}
	}

}

template<class Type>
bool LinkedList<Type>::searchList(const Type& data) {

	ListNode<Type> * current = this->mp_first;
	bool found = false;

	if (current == NULL) {
		cout <<endl <<"List is empty";
		found = false;
	}
	else {
		while (current != NULL && !found) {
			if (current->data == data) {
				found = true;
				break;
			}
			current = current->next;
		}
	}
	return found;
}
