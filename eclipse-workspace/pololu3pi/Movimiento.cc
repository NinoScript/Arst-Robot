/*
 * Movimiento.cc
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#include "Movimiento.h"

void Movimiento::avanzarUnCuadrado () {
	OrangutanMotors::setSpeeds(velocidad_maxima_avance,
				   velocidad_maxima_avance);
	delay_ms(factor_velocidad);
}

void Movimiento::girarDerecha () {
	OrangutanMotors::setSpeeds(velocidad_maxima_giro,
				   -velocidad_maxima_giro);
	delay_ms(factor_giro);
}

void Movimiento::actualizarFactores (unsigned char new_velocidad_maxima_avance,
				     unsigned char new_velocidad_maxima_giro) {
	velocidad_maxima_avance = new_velocidad_maxima_avance;
	velocidad_maxima_giro = new_velocidad_maxima_giro;
	factor_velocidad = 47500 / velocidad_maxima_avance;
	factor_giro = 16000 / velocidad_maxima_giro;
}
