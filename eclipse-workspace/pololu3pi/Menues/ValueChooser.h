/*
 * ValueChooser.h
 *
 *  Created on: Nov 12, 2012
 *      Author: ninoscript
 */

#ifndef VALUECHOOSER_H_
#define VALUECHOOSER_H_

#include "MenuItem.h"

template<typename T>
class ValueChooser : public MenuItem {
public:
	T & value;
	T minimum, maximum, step_size;
	ValueChooser (T & value, T minimum, T maximum, T step_size,
		      const char * titulo);
	virtual unsigned char open ();
};

template<typename T>
ValueChooser<T>::ValueChooser (T & value, T minimum, T maximum, T step_size,
			       const char * titulo) :
		MenuItem(titulo),
		value(value),
		minimum(minimum),
		maximum(maximum),
		step_size(step_size) {

}

template<typename T>
unsigned char ValueChooser<T>::open () {
	OrangutanLCD::print("=       ");
	OrangutanLCD::gotoXY(2, 0);
	OrangutanLCD::print(static_cast<int>(value));
	OrangutanLCD::gotoXY(0, 1);
	OrangutanLCD::print("-A");
	OrangutanLCD::gotoXY(6, 1);
	OrangutanLCD::print("+C");
	OrangutanLCD::gotoXY(0, 0);

	while (button_is_pressed(ANY_BUTTON));
	char button = wait_for_button_press(ANY_BUTTON);

	if (checkPressedState(button, BUTTON_A)) {
		value = max(value - step_size, static_cast<int>(minimum));
	} else if (checkPressedState(button, BUTTON_C)) {
		value = min(value + step_size, static_cast<int>(maximum));
	}
	return button;
}

#endif /* VALUECHOOSER_H_ */
