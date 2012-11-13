/*
 * MenuItem.h
 *
 *  Created on: Nov 12, 2012
 *      Author: ninoscript
 */

#ifndef MENUITEM_H_
#define MENUITEM_H_

#include "../Arst.h" // Para usar PROGMEM
class MenuItem {
protected:
	MenuItem (const char * titulo) :
			titulo(titulo) {
	}
public:
	const char * titulo;
	virtual unsigned char open () {
		return 0;
	}
	// virtual void operator() = 0; En vez de functor, functionoid ;)
};

#endif /* MENUITEM_H_ */
