/*
 * LinkedQueue.hpp
 *
 *  Created on: Oct 23, 2013
 *      Author: lahma016
 */

#ifndef LINKEDQUEUE_HPP_
#define LINKEDQUEUE_HPP_

#include <iostream>
#include "Node.hpp"
#include <cstdlib>

template <class Type>
class LinkedQueue {
public:
	LinkedQueue();
	virtual ~LinkedQueue();
	explicit LinkedQueue(const LinkedQueue& original);
	const LinkedQueue& operator = (const LinkedQueue& original);
	int getLength() const;
	bool empty() const;
	Type front() const;
	Type back() const;
	void enqueue (const Type& elem);
	void dequeue();
	void destroyQueue();
	void display() const;

private:
	void copyQueue (const LinkedQueue& original);
	Node<Type>* createNode (const Type& data);
	Node<Type> *mp_front;
	Node<Type> *mp_back;
	int m_length;
}; //End of class declaraton

////////////////////////////////////////////////////////////////////////////////
//    Class Implementation /Definition
////////////////////////////////////////////////////////////////////////////////


template<class Type>
inline LinkedQueue<Type>::LinkedQueue() : mp_front(NULL),mp_back(NULL),m_length(0){
}

template<class Type>
inline LinkedQueue<Type>::~LinkedQueue() {
}

template<class Type>
inline LinkedQueue<Type>::LinkedQueue(const LinkedQueue& original) {
	copyQueue(original);
}

template<class Type>
inline const LinkedQueue<Type>& LinkedQueue<Type>::operator = (
		const LinkedQueue& original) {
	if (this != &original) { //Avoid self assignment
		copyQueue(original);
	}
	return *this;
}

template<class Type>
inline int LinkedQueue<Type>::getLength() const {
	return m_length;
}

template<class Type>
inline bool LinkedQueue<Type>::empty() const {
	return (mp_front == NULL);
}

template<class Type>
inline Type LinkedQueue<Type>::front() const {
	if (empty())
		throw QueueException ("Queue is Empty");
	return mp_front->data;
}

template<class Type>
inline Type LinkedQueue<Type>::back() const {
	return mp_back->data;
}

template<class Type>
inline void LinkedQueue<Type>::enqueue(const Type& elem) {

	Node<Type> * newNode = createNode(elem);

	//Case 1: Queue is empty
	if (mp_front == NULL) {
		mp_front = newNode;
		mp_back = newNode;
	}

	//Case 2: Enqueue at the back
	else {
		mp_back->next = newNode;
		mp_back = newNode;
	}
	m_length ++;
}

template<class Type>
inline void LinkedQueue<Type>::dequeue() {

	if (empty())
		throw QueueException("Queue is Empty");

	Node<Type> *current = mp_front;
	mp_front = mp_front->next;
	delete current;
	m_length --;
}

template<class Type>
inline void LinkedQueue<Type>::destroyQueue() {

	if (mp_front == NULL)
		throw QueueException("Queue is empty");


	while (mp_front != NULL) {
		Node<Type> * current = mp_front;
		mp_front =  mp_front->next;
		delete current;
	}

	mp_back = NULL;
	mp_front = NULL;
	m_length = 0;
}

template<class Type>
inline void LinkedQueue<Type>::copyQueue(const LinkedQueue& original) {

	if (this->mp_front != NULL)
		destroyQueue();

	m_length = original.m_length;
	Node<Type> * current = original.mp_front;
	Node<Type>* newNode = createNode(current->data);
	mp_front = newNode;
	mp_back = newNode;

	//Loop the orignial queue;
	while (current != NULL) {
		newNode = createNode(current->data);
		mp_back->next = newNode;
		mp_back = newNode;
		current = current->next;
	}
}

template<class Type>
inline void LinkedQueue<Type>::display() const {
	Node<Type> *current = mp_front;
	if (current == NULL)
		throw QueueException("Queue is Empty");

	while (current != NULL) {
		std::cout << "\nItem -> " << current->data;
		current = current->next;
	}
}

template<class Type>
inline Node<Type>* LinkedQueue<Type>::createNode(const Type& data) {
	Node<Type> *newNode = new Node<Type>;

	if (newNode == NULL) {
		std::cerr<<std::endl <<"Unable to allocate node";
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

#endif /* LINKEDQUEUE_HPP_ */
