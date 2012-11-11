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
	unsigned int factorVelocidad;
	unsigned int factorGiro;

	void avanzarUnCuadrado ();
	void girarDerecha ();

	void actualizarFactores(unsigned char velocidad_maxima);
};

#endif /* MOVIMIENTO_H_ */
