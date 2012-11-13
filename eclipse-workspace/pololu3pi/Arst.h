/*
 * Arst.h
 *
 *  Created on: Nov 12, 2012
 *      Author: ninoscript
 */

#ifndef ARST_H_
#define ARST_H_

#include <pololu/3pi.h>
#include "Math/Math.h"

#define checkPressedState(button_list, button_to_check) (button_list & button_to_check)

#endif /* Arst_H_ */

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
