/*
 * StaticCircularQueue.hpp
 *
 *  Created on: Oct 23, 2013
 *      Author: lahma016
 */

#ifndef STATICCIRCULARQUEUE_HPP_
#define STATICCIRCULARQUEUE_HPP_

#include <iostream>

/*!
 * Implements circular static queue
 */

const int MAX_SIZE = 10;
template<class Type>
class StaticCircularQueue {
public:
	StaticCircularQueue();
	virtual ~StaticCircularQueue();
	StaticCircularQueue (const StaticCircularQueue &original);
	bool empty() const;
	Type front() const;
	void enqueue(const Type &item);
	void dequeue();
	void display() const;
	void data();

private:
	int m_front;
	int m_back;
	Type m_circularQueue[MAX_SIZE];
};



template<class Type>
inline StaticCircularQueue<Type>::StaticCircularQueue() : m_front(0),m_back(0) {
}

template<class Type>
inline StaticCircularQueue<Type>::~StaticCircularQueue() {
}

template<class Type>
inline StaticCircularQueue<Type>::StaticCircularQueue(const StaticCircularQueue& original) {
	m_front = original.m_front;
	m_back = original.m_back;

	for (int i = m_front; i != m_back; i = (i+1)%MAX_SIZE) {
		m_circularQueue[i] = original.m_circularQueue[i];
	}
}

template<class Type>
inline bool StaticCircularQueue<Type>::empty() const {
	return (m_front == m_back);
}

template<class Type>
inline Type StaticCircularQueue<Type>::front() const {

	if (empty())
		throw QueueException("Queue is Empty");

	return m_circularQueue[m_front];
}

template<class Type>
inline void StaticCircularQueue<Type>::enqueue(const Type& item) {

	//Increment the back to check queue is full or not
	int newBack = (m_back + 1) % MAX_SIZE;

	if (newBack == m_front)
		throw QueueException("Queue is full");

	//Equeue it the item
	m_circularQueue[m_back] = item;
	m_back = newBack; //Update the back
}

template<class Type>
inline void StaticCircularQueue<Type>::dequeue() {

	if (empty())
		throw QueueException ("Queue is Empty");

	m_front = (m_front + 1) % MAX_SIZE;
}


template<class Type>
inline void StaticCircularQueue<Type>::display() const {

	std::cout <<std::endl;
	for (int i = m_front; i != m_back; i = (i + 1)%MAX_SIZE) {
		std::cout << "Queue["<<i <<"] : " << m_circularQueue[i] << "\n";
	}
}

#endif /* STATICCIRCULARQUEUE_HPP_ */
