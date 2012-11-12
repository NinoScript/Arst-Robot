/*
 * main.cc
 *
 *  Created on: Nov 9, 2012
 *      Author: lucho
 */

#include "Robot3PI.h"
#include "Movimiento.h"

int main() {
	Movimiento movedor;

	while (1) {

		movedor.actualizarFactores();

		Robot3PI robot(movedor);
		robot.main();
	}

	return 0;
}
