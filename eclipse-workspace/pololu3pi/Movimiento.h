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
	unsigned int velocidad_maxima;
	unsigned int factor_velocidad;
	unsigned int factor_giro;
public:
	void avanzarUnCuadrado ();
	void girarDerecha ();

	void actualizarFactores (unsigned char nueva_velocidad_maxima);
};

#endif /* MOVIMIENTO_H_ */
