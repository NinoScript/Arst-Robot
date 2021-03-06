/*
 * Robot3PI.cpp
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#include "Algoritmo.h"
#include "Arst.h"

#include "Math/Point.h"

Algoritmo::Algoritmo (Movimiento & movedor) :
		movedor(movedor), rojo(3, 4) {
	puntos[0] = Point(2, 0);
	puntos[1] = Point(2, 1);
	puntos[2] = Point(1, 2);
	puntos[3] = Point(4, 3);
	puntos[4] = Point(2, 5);

	direccion = Point(0, 1);
}

void Algoritmo::calibrarSensores(){

}

int Algoritmo::run () {
//	Point e;
//	movedor.avanzarUnCuadrado();
//	movedor.girarDerecha();
//	calibrarSensores();
//	delay(500);

	posicion = puntos[0];

	for (uint8_t i = 1; i < puntos.size(); ++i) {
		Point & objetivo = puntos[i];

		while (posicion.taxicabDistanceTo(objetivo) > 0) {
			ejecutarSiguienteMovimiento(objetivo);
		}

		/* Si estamos aquí es porque ya llegamos a un punto
		 * ergo, podemos hacer ruiditos y ser felices */
		movedor.detenerse();
		OrangutanBuzzer::playFrequency(440*i, 1000, 255);
		delay_ms(1000);
//		movedor.girarDer();
//		movedor.girarIzq();
//		movedor.girarIzq();
//		movedor.girarDer();
	}

	return 0;
}

void Algoritmo::ejecutarSiguienteMovimiento (Point const & objetivo) {
	Point direccionObjetivo = (objetivo - posicion).taxicabDirection();

	bool hay_que_doblar = (direccion.x != direccionObjetivo.x
	                                   || direccionObjetivo.x == 0)
	                   && (direccion.y != direccionObjetivo.y
	                                   || direccionObjetivo.y == 0);

	if (hay_que_doblar) {
		Point nueva_direccion;
		if (direccionObjetivo.x != 0) {
			nueva_direccion = Point(direccionObjetivo.x, 0);
		} else {
			nueva_direccion = Point(0, direccionObjetivo.y);
		}
		girar(nueva_direccion);
	} // else
	avanzar();
}

void Algoritmo::avanzar () {
	posicion += direccion;

	if (posicion.x == rojo.x || posicion.y == rojo.y) {
		uint8_t distancia;
		if (direccion.y == 0) { //Estamos avanzando en X
			distancia = 10;
		} else { //Estamos avanzando en Y
			distancia = 12;
		}
		distancia-=1; //para el frenado
		movedor.avanzarUnCuadrado(distancia);
//		movedor.avanzarUnCuadrado(0); // ajustarse al final de la linea
		movedor.frenarSuave();
	} else { // Podemos seguir lineas
		movedor.avanzarUnCuadrado(5); // avanzar un poco
		movedor.avanzarUnCuadrado(0); // seguir linea
		movedor.frenarSuave();
	}
}

void Algoritmo::girar(Point nueva_direccion) {
	Point girado_der = direccion.rotated90CW();
	Point girado_izq = direccion.rotated90CCW();
	Point girado_completo = -direccion;

	if (nueva_direccion == girado_der) {
		movedor.girarDer();
	} else if (nueva_direccion == girado_izq) {
		movedor.girarIzq();
	} else if (nueva_direccion == girado_completo) {
		movedor.girarEnU();
	} else {
		// Esto no debería pasar jamaz
	}

	direccion = nueva_direccion;
}
