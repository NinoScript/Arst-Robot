/*
 * Math.h
 *
 *  Created on: Nov 13, 2012
 *      Author: ninoscript
 */

#ifndef MATH_H_
#define MATH_H_

#include <stdint.h>

template<typename T>
T max (T a, T b) {
	return a > b ? a : b;
}

template<typename T>
T min (T a, T b) {
	return a < b ? a : b;
}

template<typename T>
T abs (T n) {
	return n < 0 ? -n : n;
}

template<typename T>
int8_t sgn (T n) {
	return n>0 ? 1 : n<0 ? -1 : 0;
}

#endif /* MATH_H_ */
