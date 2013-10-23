/*
 * Node.hpp
 *
 *  Created on: Oct 23, 2013
 *      Author: lahma016
 */

#ifndef NODE_HPP_
#define NODE_HPP_
template<class Type>
struct Node {
	Type data;
	struct Node<Type> * next;
};

#endif /* NODE_HPP_ */
