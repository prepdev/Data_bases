/*
 * QueueException.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: lahma016
 */

#include "QueueException.hpp"
#include <stdio.h>

QueueException::QueueException(const char* ex) : errorMessage(ex){
}

const char* QueueException::error() const {
	return errorMessage;
}
