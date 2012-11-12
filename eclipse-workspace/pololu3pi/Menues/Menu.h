/*
 * Menu.h
 *
 *  Created on: Nov 11, 2012
 *      Author: ninoscript
 */

#ifndef MENU_H_
#define MENU_H_

#include "MenuItem.h"

class Menu : public MenuItem {
public:
	MenuItem ** funcs_array;
	int amount_of_funcs;
	int menu_index;

	Menu (MenuItem ** funcs_array, unsigned int amount_of_funcs);

	virtual unsigned char open ();
	static void playSound (unsigned char button);

private:
	static const char menu_line2[] PROGMEM;
	static const char back_line2[] PROGMEM;
	static const char beep_button_a[] PROGMEM;
	static const char beep_button_b[] PROGMEM;
	static const char beep_button_c[] PROGMEM;

};

#endif /* MENU_H_ */
