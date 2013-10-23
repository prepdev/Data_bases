//============================================================================
// Name        : Queue.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Queue/QueueException.hpp"
#include "Queue/StaticCircularQueue.hpp"
#include "Queue/LinkedQueue.hpp"
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {

	StaticCircularQueue<int> q;
	LinkedQueue<int> queue;
	srand(time(NULL));
try {
	for (int i = 1; i < 9; i ++)
		queue.enqueue(rand() % 10);

	queue.display();
	cout <<endl <<"Length is " <<queue.getLength();
	cout <<endl <<"Front is " <<queue.front();
	cout <<endl <<"==================";
	queue.dequeue();
	queue.dequeue();
	cout <<endl <<"Front is " <<queue.front();
	cout <<endl <<"Back is " <<queue.back();

	LinkedQueue<int> queue1;
	queue1 = queue;
	queue1.display();



}
catch (QueueException &ex) {
	cout <<endl << ex.error();
}

	return 0;
}
