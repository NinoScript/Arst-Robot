/*
 * Menu.h
 *
 *  Created on: Nov 11, 2012
 *      Author: ninoscript
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "MenuItem.h"
#include "../utils/Binder.h"

class MainMenu : public MenuItem {
public:
	MenuItem ** funcs_array;
	int amount_of_funcs;
	int menu_index;
	Caller * callback;

	MainMenu (MenuItem ** funcs_array, unsigned int amount_of_funcs,
		  Caller * callback);

	virtual unsigned char open ();
	static void playSound (unsigned char button);

private:
	static const char menu_line2[] PROGMEM;
	static const char back_line2[] PROGMEM;
	static const char beep_button_a[] PROGMEM;
	static const char beep_button_b[] PROGMEM;
	static const char beep_button_c[] PROGMEM;

};

#endif /* MAINMENU_H_ */
