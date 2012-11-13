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
	unsigned char velocidad_maxima_avance;
	unsigned char velocidad_maxima_giro;
	unsigned int factor_velocidad;
	unsigned int factor_giro;
public:
	void avanzarUnCuadrado ();
	void girarDerecha ();

	void actualizarFactores (unsigned char velocidad_maxima_avance,
				 unsigned char velocidad_maxima_giro);
};

#endif /* MOVIMIENTO_H_ */
