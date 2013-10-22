/*
 * UnOrderedList.hpp
 *
 *  Created on: Oct 20, 2013
 *      Author: lahmad
 */

#ifndef UNORDEREDLIST_HPP_
#define UNORDEREDLIST_HPP_

#include "ArrayList.hpp"

class UnOrderedList: public ArrayList {
public:
	explicit UnOrderedList(int size = 100);
	virtual ~UnOrderedList();
	void remove(int item);
	void insertAt(int loc, int item);
	void replaceAt(int loc, int item);
	void add(int item);


};

#endif /* UNORDEREDLIST_HPP_ */
