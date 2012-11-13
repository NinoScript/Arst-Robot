/*
 * FunctorInvoker.h
 *
 *  Created on: Nov 13, 2012
 *      Author: ninoscript
 */

#ifndef METHODINVOKER_H_
#define METHODINVOKER_H_

#define MNGLD_T(tipo) tipo##_internal_t
#define CREAR_METHOD_INVOKER(nombre_menu, objeto, metodo, titulo) \
	typedef typeof(objeto) MNGLD_T(nombre_menu); \
	MethodInvoker<  MNGLD_T(nombre_menu), \
	              & MNGLD_T(nombre_menu) :: metodo> \
		nombre_menu (objeto, PSTR(titulo))


#include "MenuItem.h"
#include "../Utils/Binder.h"

template<typename T, void (T::*method)()>
class MethodInvoker : public MenuItem, public Binder<T, method> {
public:
	MethodInvoker (T & object, pgmspace_string titulo) : MenuItem(titulo), Binder<T, method>(object) {}
	virtual unsigned char open () {
		OrangutanLCD::printFromProgramSpace(titulo);
		OrangutanLCD::gotoXY(0, 0);

		/* tiempo prudente para alcanzar a soltar el boton */
		while (button_is_pressed(ANY_BUTTON));
		delay_ms(500);

		this->call();

		return wait_for_button_press(ANY_BUTTON);
	}
};

#endif /* METHODINVOKER_H_ */
