/*
 * ListNode.hpp
 *
 *  Created on: 2013-10-21
 *      Author: luqman
 */

#ifndef LISTNODE_HPP_
#define LISTNODE_HPP_
template <class Type>
struct ListNode {
	Type data;
	ListNode<Type> *next;
};
#endif /* LISTNODE_HPP_ */
