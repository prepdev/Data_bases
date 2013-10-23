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
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {

	StaticCircularQueue<int> q;
	srand(time(NULL));
try {
	for (int i = 1; i < 9; i ++)
		q.enqueue(rand() % 10);

	q.display();

	cout <<endl <<"Front Item is " << q.front();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	cout <<endl <<"Front Item is " << q.front();
	q.display();


	q.enqueue(40);
	q.enqueue(140);
	q.enqueue(240);
	q.enqueue(9);
	q.enqueue(29);


}
catch (QueueException &ex) {
	cout <<endl << ex.error();
}

	return 0;
}
