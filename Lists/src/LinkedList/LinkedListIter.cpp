/*
 * LinkedListIter.cpp
 *
 *  Created on: 2013-10-21
 *      Author: luqman
 */

#include "LinkedListIter.hpp"

template<class Type>
LinkedListIter<Type>::LinkedListIter() {
	mp_current = 0;
}

template<class Type>
LinkedListIter<Type>::~LinkedListIter() {
}


template<class Type>
LinkedListIter<Type>::LinkedListIter(ListNode<Type>* nodePtr) {
	mp_current = nodePtr;
}

template<class Type>
Type LinkedListIter<Type>::operator *(const ListNode<Type>* node) {
	return node->data;
}

template<class Type>
bool LinkedListIter<Type>::operator ==(const LinkedListIter<Type> & original) {
	return (mp_current == original.mp_current);
}

template<class Type>
bool LinkedListIter<Type>::operator !=(const LinkedListIter<Type> & original) {
	return (mp_current != original.mp_current);

}
template <class Type>
void LinkedListIter<Type>::operator ++() {
	mp_current = mp_current->next;
}
