/*
 * Robot3PI.h
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#ifndef ROBOT3PI_H_
#define ROBOT3PI_H_

#include "Movimiento.h"

class Robot3PI {
	int max;
	Movimiento & movedor;

public:
	Robot3PI (Movimiento & movedor);
	int main ();

	int ajustavelmax (int max);
};

#endif /* ROBOT3PI_H_ */
