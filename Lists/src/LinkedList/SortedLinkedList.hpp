/*
 * SortedLinkedList.hpp
 *
 *  Created on: 2013-10-21
 *      Author: luqman
 */

#ifndef SORTEDLINKEDLIST_HPP_
#define SORTEDLINKEDLIST_HPP_

#include "LinkedList.hpp"

template<class Type>
class SortedLinkedList: public LinkedList<Type> {
public:
	SortedLinkedList();
	virtual ~SortedLinkedList();
	void insertFirst(const Type& data);
	void insertLast(const Type& data);
private:
	void insert(const Type& data);
};


#endif /* SORTEDLINKEDLIST_HPP_ */
