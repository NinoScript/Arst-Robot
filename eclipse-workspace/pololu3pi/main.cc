/*
 * main.cc
 *
 *  Created on: Nov 9, 2012
 *      Author: lucho
 */

#include "Robot3PI.h"
//#include "Movimiento.h"

#include "Menu.h"

// This character is a back arrow.
const char back_arrow[] PROGMEM = { 0b00000, 0b00010, 0b00001, 0b00101, 0b01001,
		0b11110, 0b01000, 0b00100, };

int main() {
	OrangutanLCD::clear();
	OrangutanLCD::print("3Pi-ARST");
	OrangutanBuzzer::play(">g32>>c32>g32>>c32>g32>>c32");
	while (OrangutanBuzzer::isPlaying())
		;

	lcd_load_custom_character(back_arrow, 6);

	int velocidad_maxima = 80;
	ValueChooser<int> velocidad_maxima_chooser(velocidad_maxima, 50, 180, 5,
			"max vel");

	unsigned char veces = 2;
	ValueChooser<unsigned char> veces_chooser(veces, 1, 8, 1, "veces");

	MenuItem* menu_items[] = { &velocidad_maxima_chooser, &veces_chooser };
	Menu menu_principal(menu_items, sizeof(menu_items) / sizeof(menu_items[0]));

	Movimiento movedor;
	while (1) {
		menu_principal.open();
		movedor.actualizarFactores(velocidad_maxima);

		Robot3PI robot(movedor);

		clear();
		print("Press B");
		lcd_goto_xy(0, 1);
		print("And Wait");
		OrangutanPushbuttons::waitForButton(BUTTON_B);
		OrangutanBuzzer::play("!L16 V8 cdefgab>cbagfedc");//>g32>>c32");
		delay_ms(500);
		for (unsigned char i = 0; i < veces; ++i) {
			robot.run();
		}
	}

	return 0;
}
