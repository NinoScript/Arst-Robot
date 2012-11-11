/*
 * Movimiento.h
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#ifndef MOVIMIENTO_H_
#define MOVIMIENTO_H_

#include "pololu/3pi.h"

class Movimiento {
public:
	unsigned int velmax;

	void avanzarUnCuadrado ();
	void girarDerecha ();
};

#endif /* MOVIMIENTO_H_ */
