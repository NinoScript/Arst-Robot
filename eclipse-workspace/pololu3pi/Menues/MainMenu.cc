/*
 * Menu.cpp
 *
 *  Created on: Nov 11, 2012
 *      Author: ninoscript
 */

#include "MainMenu.h"

const char MainMenu::menu_line2[] = "\x7f" "A \xa5" "B C\x7e";
const char MainMenu::back_line2[] = "\6B";
const char MainMenu::beep_button_a[] = "!c32";
const char MainMenu::beep_button_b[] = "!e32";
const char MainMenu::beep_button_c[] = "!g32";

MainMenu::MainMenu (MenuItem ** funcs_array, unsigned int amount_of_funcs,
		    Caller * callback) :
		MenuItem("MainMenu"),
		funcs_array(funcs_array),
		amount_of_funcs(amount_of_funcs),
		menu_index(amount_of_funcs),
		callback(callback) {
}

void MainMenu::playSound (unsigned char button) {
	if (checkPressedState(button, BUTTON_A)) {
		play_from_program_space(MainMenu::beep_button_a);
	} else if (checkPressedState(button, BUTTON_B)) {
		play_from_program_space(MainMenu::beep_button_b);

	} else if (checkPressedState(button, BUTTON_C)) {
		play_from_program_space(MainMenu::beep_button_c);
	}
}

unsigned char MainMenu::open () {
	set_motors(0, 0);
	stop_playing();
	red_led(0);
	green_led(0);

	while (1) {
		clear();
		lcd_goto_xy(0, 1);
		print_from_program_space(MainMenu::menu_line2);
		lcd_goto_xy(0, 0);

		/* Esto es para poder llevar a cabo las configuraciones */
		callback->call();

		if (menu_index == amount_of_funcs) {
			print_from_program_space(PSTR("Run!"));
		} else {
			print_from_program_space(
					funcs_array[menu_index]->titulo);
		}
		lcd_show_cursor(CURSOR_BLINKING);
		// the cursor will be blinking at the end of the option name

		// wait for all buttons to be released, then a press
		while (button_is_pressed(ANY_BUTTON))
			;
		char button = wait_for_button_press(ANY_BUTTON);
		MainMenu::playSound(button);

		if (checkPressedState(button, BUTTON_A)) {
			menu_index--;
		} else if (checkPressedState(button, BUTTON_B)) {
			lcd_hide_cursor();
			clear();

			do {
				if (menu_index == amount_of_funcs) {
					return 0;
				} else {
					lcd_goto_xy(3, 1);
					print_from_program_space(
							MainMenu::back_line2);
					lcd_goto_xy(0, 0);
					// funcs_array[menu_index]();
					button = funcs_array[menu_index]->open();
					MainMenu::playSound(button);
				}
			} while (!checkPressedState(button, BUTTON_B));
			continue;
		} else if (checkPressedState(button, BUTTON_C)) {
			menu_index++;
		}

		if (menu_index < 0) menu_index = amount_of_funcs;
		if (menu_index > amount_of_funcs) menu_index = 0;
	}
	return 0;
}
