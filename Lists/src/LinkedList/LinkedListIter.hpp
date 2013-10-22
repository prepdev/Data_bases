/*
 * LinkedListIter.hpp
 *
 *  Created on: 2013-10-21
 *      Author: luqman
 */

#ifndef LINKEDLISTITER_HPP_
#define LINKEDLISTITER_HPP_
#include "ListNode.hpp"

template <class Type>
class LinkedListIter {
public:
	LinkedListIter();
	virtual ~LinkedListIter();
	explicit LinkedListIter(ListNode<Type> *nodePtr);
	Type operator *(const ListNode<Type> *node);
	bool operator == (const LinkedListIter<Type> &original);
	bool operator != (const LinkedListIter<Type> &original);
	void operator ++ ();
private:
	ListNode<Type>* mp_current;
};

#endif /* LINKEDLISTITER_HPP_ */
