/*
 * Arst3Pi.h
 *
 *  Created on: Nov 13, 2012
 *      Author: ninoscript
 */

#ifndef ARST3PI_H_
#define ARST3PI_H_

#include "Arst.h"

#include "Movimiento.h"

class Arst3Pi {
public:
	int main ();
	Arst3Pi ();
private:
	static const char back_arrow[] PROGMEM;
	Movimiento movedor;
	Pololu3pi robot;
	void lecturaSensores();
	unsigned int sensors[5];
};

#endif /* ARST3PI_H_ */

