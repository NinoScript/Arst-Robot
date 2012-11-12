/*
 * Menu.h
 *
 *  Created on: Nov 11, 2012
 *      Author: ninoscript
 */

#ifndef MENU_H_
#define MENU_H_

#include <pololu/3pi.h>
//#include <pololu/OrangutanLCD.h>
//#include <pololu/OrangutanPushbuttons.h>
//#include <pololu/OrangutanBuzzer.h>



class MenuItem {
protected:
	MenuItem(const char * titulo) :
			titulo(titulo) {
	}
public:
	const char * titulo;
	virtual unsigned char open() {return 0;}
	// virtual void operator() = 0; En vez de functor, functionoid ;)
//	virtual ~MenuItem() {
//	}
};

namespace std {
template<typename T>
T max(T a, T b) {
	return a > b ? a : b;
}

template<typename T>
T min(T a, T b) {
	return a < b ? a : b;
}
}

#define checkPressedState(button_list, button_to_check) (button_list & button_to_check)

template<typename T>
class ValueChooser: public MenuItem {
public:
	T & value;
	T minimum, maximum, step_size;
	// const char welcome[] PROGMEM
	ValueChooser(T & value, T minimum, T maximum, T step_size,
			const char * titulo) :
			MenuItem(titulo), value(value), minimum(minimum), maximum(maximum), step_size(
					step_size) {

	}
	virtual unsigned char open() {
		OrangutanLCD::print("=       ");
		OrangutanLCD::gotoXY(2,0);
		OrangutanLCD::print(static_cast<int>(value));
		OrangutanLCD::gotoXY(0,1);
		OrangutanLCD::print("-A");
		OrangutanLCD::gotoXY(6,1);
		OrangutanLCD::print("+C");
		OrangutanLCD::gotoXY(0,0);

		while(button_is_pressed(ANY_BUTTON));
		char button = wait_for_button_press(ANY_BUTTON);

		if (checkPressedState(button, BUTTON_A)) {
			value = std::max(value - step_size, static_cast<int>(minimum));
//			OrangutanPushbuttons::waitForRelease(BUTTON_A);
		} else if (checkPressedState(button, BUTTON_C)) {
			value = std::min(value + step_size, static_cast<int>(maximum));
//			OrangutanPushbuttons::waitForRelease(BUTTON_C);
		}
		return button;
	}
//	virtual ~ValueChooser() {
//	}
};

class Menu: public MenuItem {
public:
	MenuItem ** funcs_array;
	unsigned int amount_of_funcs;
	unsigned int menu_index;

	Menu(MenuItem ** funcs_array, unsigned int amount_of_funcs);

	// print_two_lines_delay_1s(main_menu_intro_line1,main_menu_intro_line2);
	virtual unsigned char open();
	static void playSound (unsigned char button);
//	virtual ~Menu() {
//	}
private:
	static const char menu_line2[] PROGMEM;
	static const char back_line2[] PROGMEM;
	static const char beep_button_a[] PROGMEM;
	static const char beep_button_b[] PROGMEM;
	static const char beep_button_c[] PROGMEM;

};

/* The __cxa_pure_virtual function is an error handler
 * that is invoked when a pure virtual function is called.
 *
 * If you are writing a C++ application that
 * has pure virtual functions you must supply
 * your own __cxa_pure_virtual error handler function.
 * For example:
 * extern "C" void __cxa_pure_virtual() { while (1); }
 */
//extern "C" void __cxa_pure_virtual() {
//	OrangutanLCD::clear();
//	OrangutanLCD::print("PurVirtE");
//	while (1);
//}

#endif /* MENU_H_ */
