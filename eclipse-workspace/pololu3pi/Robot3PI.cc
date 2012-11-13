/*
 * Robot3PI.cpp
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#include "Robot3PI.h"
#include "Arst.h"

#include "Math/Point.h"

Robot3PI::Robot3PI (Movimiento & movedor) :
		movedor(movedor) {
}

int Robot3PI::run () {
	Point e;
	movedor.avanzarUnCuadrado();
	movedor.girarDerecha();

	set_motors(0, 0);
	return 0;
}
