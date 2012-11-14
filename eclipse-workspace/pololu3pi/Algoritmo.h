/*
 * Algoritmo.h
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#ifndef ALGORITMO_H_
#define ALGORITMO_H_

#include "Movimiento.h"

#include "Utils/Array.h"
#include "Math/Point.h"
typedef Array<Point, 5> lista_puntos_t;

class Algoritmo {
public:
	Algoritmo (Movimiento & movedor);
	int run ();
	static void calibrarSensores ();

private:
	void ejecutarSiguienteMovimiento (Point const & objetivo);
	void avanzar ();
	void girar(Point nueva_direccion);

	Movimiento & movedor;
	lista_puntos_t puntos;
	Point posicion;
	Point direccion;
};

#endif /* ALGORITMO_H_ */

