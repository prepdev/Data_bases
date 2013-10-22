/*
 * OrderedList.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: lahmad
 */

#include "OrderedList.hpp"
#include <iostream>

using namespace std;

OrderedList::OrderedList(int size) :
		ArrayList(size) {
}

OrderedList::~OrderedList() {
}

void OrderedList::remove(int item) {

}

void OrderedList::insertAt(int loc, int item) {
	if (!isFull()) {
		if (boundCheck(loc)) {
			add(item);
		}
	}
}

void OrderedList::replaceAt(int loc, int item) {

	if (boundCheck(loc)) {
		if (loc == 0)
			add(item);
		else if (m_list[loc - 1] > item) {
			m_list[loc] = m_list[loc - 1];
			m_list[loc - 1] = item;
		}
	}
}

void OrderedList::add(int item) {

	if (isEmpty()) {
		m_list[m_length++] = item;
	} else if (isFull()) {
		cout << endl << "List is Full";
	} else {

		//Find the largest or equal first
		int loc = 0;
		bool found = false;
		while (loc < m_length && !found) {
			if (m_list[loc] >= item) {
				found = true;
			} else {
				loc++;
			}
		}

		//Insert now
		for (int i = m_length; i > loc; i--) {
			m_list[i] = m_list[i - 1];
		}
		m_list[loc] = item;
		m_length++;
	}
}
