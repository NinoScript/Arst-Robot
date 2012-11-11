/*
 * Movimiento.cc
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#include "Movimiento.h"

void Movimiento::avanzarUnCuadrado () {
	OrangutanMotors::setSpeeds(velmax, velmax);
	delay_ms(500);
}

void Movimiento::girarDerecha () {
	OrangutanMotors::setSpeeds(velmax, -velmax);
	delay_ms(tProp);
}
