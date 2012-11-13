/*
 * ValueChooser.h
 *
 *  Created on: Nov 12, 2012
 *      Author: ninoscript
 */

#ifndef VALUECHOOSER_H_
#define VALUECHOOSER_H_

#define CREAR_VALUE_CHOOSER(obj, var, titulo, minv, defv, maxv, step) \
	obj.var = defv; \
	ValueChooser<typeof(obj.var)> menu_##var (obj.var, minv, maxv, step, PSTR(titulo))

#include "MenuItem.h"

template<typename T>
class ValueChooser : public MenuItem {
public:
	T & value;
	T minimum, maximum, step_size;
	ValueChooser (T & value, T minimum, T maximum, T step_size,
	              pgmspace_string titulo);
	virtual unsigned char open ();
};

template<typename T>
ValueChooser<T>::ValueChooser (T & value, T minimum, T maximum, T step_size,
                               pgmspace_string titulo) :
		MenuItem(titulo),
		value(value),
		minimum(minimum),
		maximum(maximum),
		step_size(step_size) {

}

typedef int16_t bignum_t;

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

	while (button_is_pressed(ANY_BUTTON))
		;
	char button = wait_for_button_press(ANY_BUTTON);

	if (checkPressedState(button, BUTTON_A)) {
		value = max(static_cast<bignum_t>(value - step_size),
			    static_cast<bignum_t>(minimum));
	} else if (checkPressedState(button, BUTTON_C)) {
		value = min(static_cast<bignum_t>(value + step_size),
			    static_cast<bignum_t>(maximum));
	}
	return button;
}

#endif /* VALUECHOOSER_H_ */
