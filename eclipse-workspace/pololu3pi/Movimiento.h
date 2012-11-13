/*
 * Movimiento.h
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#ifndef MOVIMIENTO_H_
#define MOVIMIENTO_H_

#include <pololu/3pi.h>
#include "point.h"

class Movimiento {
public:

	void avanzarUnCuadrado ();
	void girarDer ();
	void girarIzq ();
	void girarEnU ();
	void detenerse ();

	int mover (point & posicion, point const & objetivo, point & direccion);

//	void actualizarFactores (unsigned char new_velocidad_maxima_avance,
//				 unsigned char new_velocidad_maxima_giro,
//				 unsigned int new_factor_distancia,
//				 unsigned int new_factor_angulo);

	uint8_t velocidad_maxima_avance;
	uint8_t velocidad_maxima_giro;
	uint16_t factor_distancia; //47500
	uint16_t factor_angulo;    //16000
	void actualizarFactores ();
private:

	uint16_t tiempo_velocidad;
	uint16_t tiempo_giro;
};

#endif /* MOVIMIENTO_H_ */
