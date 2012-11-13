/*
 * Robot3PI.cpp
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#include "Arst3Pi.h"

#include "Utils/Array.h"
#include "Math/Point.h"

#include "Algoritmo.h"
#include "Menues.h"

// This character is a back arrow.
const char Arst3Pi::back_arrow[] PROGMEM
= { 0b00000, 0b00010, 0b00001, 0b00101, 0b01001, 0b11110, 0b01000, 0b00100, };

int Arst3Pi::main () {

	/* Hacer unos ruiditos al inicio y mostrar algo en la pantalla */
	OrangutanLCD::clear();
	OrangutanLCD::print("3Pi-ARST");
	OrangutanBuzzer::play(">g32>>c32>g32>>c32>g32>>c32");

	/* Mostrar estado de las baterías al inicio */
	while (!button_is_pressed(ALL_BUTTONS)) {
		int bat = read_battery_millivolts();

		lcd_goto_xy(0, 1);
		print_long(bat);
		print(" mV");

		delay_ms(100);
	}

	while (button_is_pressed(ALL_BUTTONS))
		;

	/* Cargar el caracter "devolverse", lo ocupan varias cosas en \6 */
	lcd_load_custom_character(Arst3Pi::back_arrow, 6);

	/* aca genero los elementos del menú para configurar cosas */
	CREAR_VALUE_CHOOSER(movedor, velocidad_maxima_avance, //
			    "V.avance", 50, 100, 180, 5);
	CREAR_VALUE_CHOOSER(movedor, velocidad_maxima_giro, //
			    "V.giro", 50, 80, 180, 5);
	CREAR_VALUE_CHOOSER(movedor, factor_distancia, //
			    "F.dist", 1000, 4750, 8000, 250);
	CREAR_VALUE_CHOOSER(movedor, factor_angulo, //
			    "F.angulo", 500, 1500, 3000, 100);
	CREAR_METHOD_INVOKER(menu_giro_test, movedor, girarDer, "giro");

	/* luego meto los elementos al menú y creo el menú */
	MenuItem* menu_items[] = { &menu_velocidad_maxima_avance,
				   &menu_velocidad_maxima_giro,
				   &menu_factor_distancia, &menu_factor_angulo,
				   &menu_giro_test };

	/* esto se llama al entrar al menu principal
	 * o al salir de alguno de sus elementos */
	Binder<Movimiento, &Movimiento::actualizarFactores> aplicador(movedor);

	MainMenu menu_principal(menu_items,
				sizeof(menu_items) / sizeof(menu_items[0]),
				&aplicador);

	while (1) {
		menu_principal.open();

		Algoritmo robot(movedor);

		clear();
		print("Press B");
		lcd_goto_xy(0, 1);
		print("And Wait");
		OrangutanPushbuttons::waitForButton(BUTTON_B);
//		OrangutanBuzzer::play("!L16 V8 cdefgab>cbagfedc"); //>g32>>c32");

		/* tiempo prudente para alcanzar a soltar el boton */
		delay_ms(500);

//		for (unsigned char i = 0; i < veces; ++i)
		robot.run();
	}

	return 0;
}

//void aplicarValores () {
//	movedor.actualizarFactores(velocidad_maxima_avance,
//				   velocidad_maxima_giro, factor_distancia,
//				   factor_angulo);
//}
