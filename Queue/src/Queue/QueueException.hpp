/*
 * QueueException.hpp
 *
 *  Created on: Oct 23, 2013
 *      Author: lahma016
 */

#ifndef QUEUEEXCEPTION_HPP_
#define QUEUEEXCEPTION_HPP_

#include <iostream>

class QueueException {
public:
	QueueException(const char * ex);
	const char * error() const;
private:
	const char *errorMessage;
};

#endif /* QUEUEEXCEPTION_HPP_ */
