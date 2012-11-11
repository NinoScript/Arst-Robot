/*
 * Movimiento.cc
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#include "Movimiento.h"

void Movimiento::avanzarUnCuadrado () {
	OrangutanMotors::setSpeeds(velocidad_maxima, velocidad_maxima);
	delay_ms(factor_velocidad);
}

void Movimiento::girarDerecha () {
	OrangutanMotors::setSpeeds(velocidad_maxima, -velocidad_maxima);
	delay_ms(factor_giro);
}

void Movimiento::actualizarFactores(unsigned char nueva_velocidad_maxima) {
	velocidad_maxima = nueva_velocidad_maxima;
	factor_velocidad = 47500 / velocidad_maxima;
	factor_giro      = 16000 / velocidad_maxima;
}
