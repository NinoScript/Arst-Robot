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
	delay_ms(tiempo_velocidad);
	detenerse();
}

void Movimiento::girarDer () {
	OrangutanMotors::setSpeeds(velocidad_maxima_giro,
				   -velocidad_maxima_giro);
	delay_ms(tiempo_giro);
	detenerse();
}

void Movimiento::girarIzq () {
	OrangutanMotors::setSpeeds(-velocidad_maxima_giro,
				   velocidad_maxima_giro);
	delay_ms(tiempo_giro);
	detenerse();
}

void Movimiento::girarEnU () {
	girarDer();
	girarDer();
	detenerse();
}

void Movimiento::detenerse () {
	OrangutanMotors::setSpeeds(0, 0);
}

void Movimiento::actualizarFactores () {
	tiempo_velocidad = 10 * factor_distancia / (velocidad_maxima_avance);
	tiempo_giro = 10 * factor_angulo / velocidad_maxima_giro;
}
