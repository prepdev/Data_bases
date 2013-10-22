/*
 * UnOrderedList.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: lahmad
 */

#include "UnOrderedList.hpp"
#include <iostream>

using namespace std;

UnOrderedList::UnOrderedList(int size) : ArrayList(size){
}

UnOrderedList::~UnOrderedList() {
}

void UnOrderedList::remove(int item) {
	if (!isEmpty()) {
		int pos;
		if (search(item ,pos)) {
			removeAt(pos,item);
		}
		else {
			cout <<endl <<"Unable to find the item";
		}
	}
	else {
		cerr <<endl <<"List is Empty";
	}
}

void UnOrderedList::insertAt(int loc, int item) {

	if (!isFull() && boundCheck(loc)) {
		for (int i = m_length-1 ; i > loc; --i) {
			m_list[i+1] = m_list[i];
		}
		m_list[loc] = item;
		m_length++;
	}
	else {
		cerr <<endl <<"List is Full";
	}

}

void UnOrderedList::replaceAt(int loc, int item) {
	if (!isEmpty() && boundCheck(loc)) {
		m_list[loc] = item;
	}
}

void UnOrderedList::add(int item) {
	if (!isFull()) {
		m_list[m_length -1] = item;
		m_length ++;
	}
	else {
		cerr << endl <<"List is Full";
	}
}
