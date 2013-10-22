/*
 * LinkedList.hpp
 *
 *  Created on: 2013-10-21
 *      Author: luqman
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include "ListNode.hpp"
#include "LinkedListIter.hpp"

template <class Type>
class LinkedList {
public:
	LinkedList();
	virtual ~LinkedList();
	explicit LinkedList (const LinkedList<Type> & original);
	const LinkedList<Type>& operator = (const LinkedList<Type> & original);
	void initializeList();
	void destroyList();
	void printList() const;
	Type getFirst() const;
	Type getLast() const;
	bool isEmpty() const;
	int getLength() const;
	LinkedListIter<Type> begin ();
	LinkedListIter<Type> end();
	virtual void insertFirst(const Type& data) = 0;
	virtual void insertLast(const Type& data) = 0 ;
	bool searchList (const Type& data);
	void deleteNode (const Type& data);

protected:
	ListNode<Type>* mp_first;
	ListNode<Type>* mp_last;
	int m_length;

private:
	void makeCopy(const LinkedList<Type> &original);
};

#endif /* LINKEDLIST_HPP_ */
