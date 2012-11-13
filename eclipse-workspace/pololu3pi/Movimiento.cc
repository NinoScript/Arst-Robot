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


int Movimiento::mover (point & posicion, point const & objetivo, point & direccion) {
	point distancia = objetivo - posicion;
	distancia = distancia.unitario();

	bool hay_que_doblar = (direccion.x != distancia.x || distancia.x == 0) && (direccion.y != distancia.y || distancia.y == 0) ;

	if (hay_que_doblar) {

		if (distancia.x != 0) {
			direccion.x = distancia.x;
			direccion.y = 0;
		} else {
			direccion.x = 0;
			direccion.y = distancia.y;
		}

	}

	posicion += direccion;

	// cout << "nueva posicion: " << posicion << ", despues de moverse: " << direccion << "\n\r";
	return posicion.distancia(objetivo);

}
