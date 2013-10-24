/*
 * BinaryNode.hpp
 *
 *  Created on: 2013-10-24
 *      Author: luqman
 */

#ifndef BINARYNODE_HPP_
#define BINARYNODE_HPP_

const int KEY_SIZE = 20;
const int VALUE_SIZE = 20;

/*
 * Structure representing the
 * node of the binary search tree
 */
typedef struct Node {
	int key;
	char _value[VALUE_SIZE];
	struct Node *_right;
	struct Node *_left;

}TreeNode;

#endif /* BINARYNODE_HPP_ */
