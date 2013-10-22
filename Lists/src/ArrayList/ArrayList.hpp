/*
 * ArrayList.hpp
 *
 *  Created on: Oct 20, 2013
 *      Author: lahmad
 */

#ifndef ARRAYLIST_HPP_
#define ARRAYLIST_HPP_

#include "../List.hpp"

class ArrayList: public List {
public:
	explicit ArrayList(int size = 100);
	virtual ~ArrayList();
	ArrayList (const ArrayList& rhsList);
	bool isEmpty() const;
	bool isFull() const;
	void printList() const;
	virtual void remove(int item) = 0;
	virtual void insertAt(int loc, int item) = 0;
	virtual void replaceAt(int loc, int item) = 0;
	virtual void add(int item) = 0;
	void removeAt (int loc, int item);
	void retrieveAt (int loc, int &item);
	void clearList();
	int size() const;
	void removeEnd();
	bool search(int item, int& loc);

	const int& operator [] (int index) const;
	int& operator[] (int index);

	bool operator == (const ArrayList& rhsList);
	bool operator != (const ArrayList& rhsList);
	const ArrayList& operator = (const ArrayList& rhsList);
	bool boundCheck(int loc);

protected:
	int *m_list;
	int m_size;
};

#endif /* ARRAYLIST_HPP_ */
