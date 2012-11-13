/*
 * Array.h
 *
 *  Created on: Nov 13, 2012
 *      Author: ninoscript
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <stdint.h>

template<typename T, uint8_t n>
struct Array {
	T actual_array[n];

	typedef T& reference;
	typedef const T& const_reference;

	uint8_t size () {
		return n;
	}

	reference operator[] (uint8_t i) {
		return actual_array[i];
	}
	
	const_reference operator[] (uint8_t i) const {
		return actual_array[i];
	}
};

#endif /* UTILS_H_ */
