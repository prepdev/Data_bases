/*
 * UnSortedLinkedList.hpp
 *
 *  Created on: 2013-10-21
 *      Author: luqman
 */

#ifndef UNSORTEDLINKEDLIST_HPP_
#define UNSORTEDLINKEDLIST_HPP_

#include "LinkedList.hpp"

template <class Type>
class UnSortedLinkedList: public LinkedList<Type> {
public:
	UnSortedLinkedList();
	virtual ~UnSortedLinkedList();
	void insertFirst(const Type& data);
	void insertLast(const Type& data);
};

#endif /* UNSORTEDLINKEDLIST_HPP_ */
