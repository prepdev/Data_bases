/*
 * OrderedList.hpp
 *
 *  Created on: Oct 20, 2013
 *      Author: lahmad
 */

#ifndef ORDEREDLIST_HPP_
#define ORDEREDLIST_HPP_

#include "ArrayList.hpp"

class OrderedList: public ArrayList {
public:
	explicit OrderedList(int size = 100);
	virtual ~OrderedList();
	void remove(int item);
	void insertAt (int loc, int item);
	void replaceAt (int loc, int item);
	void add (int item);
};

#endif /* ORDEREDLIST_HPP_ */
