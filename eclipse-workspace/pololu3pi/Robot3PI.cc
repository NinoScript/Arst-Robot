/*
 * Robot3PI.cpp
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#include "Robot3PI.h"
#include <pololu/3pi.h>

Robot3PI::Robot3PI(Movimiento & movedor) :
		movedor(movedor) {
}

int Robot3PI::main() {
	OrangutanBuzzer::play(">g32>>c32");
	max = 125;
	while (1) {
		max = ajustavelmax(max);
		OrangutanPushbuttons::waitForButton(BUTTON_B);

		clear();
		print("Press B");
		lcd_goto_xy(0, 1);
		print("And Wait");
		wait_for_button_press(BUTTON_B);
		wait_for_button_release(BUTTON_B);
		delay_ms(300);

		movedor.avanzarUnCuadrado();

		clear();
		movedor.girarDerecha();

		delay_ms(1200);
	}
	return 0;
}

int Robot3PI::ajustavelmax(int max) {
	clear();

	while (!button_is_pressed(BUTTON_B)) {
		OrangutanLCD::gotoXY(0, 0);
		OrangutanLCD::print("Vel: ");
		OrangutanLCD::print(max);
		if (button_is_pressed(BUTTON_A)) {
			if (max > 10)
				max -= 10;
			wait_for_button_release(BUTTON_A);
			clear();
		} else if (button_is_pressed(BUTTON_C)) {
			if (max < 246)
				max += 10;
			wait_for_button_release(BUTTON_C);
			clear();
		}
	}
	return max;
}
