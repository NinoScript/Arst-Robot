/*
 * MenuItem.h
 *
 *  Created on: Nov 12, 2012
 *      Author: ninoscript
 */

#ifndef MENUITEM_H_
#define MENUITEM_H_

#include "../Arst.h"
typedef const PROGMEM char * pgmspace_string;

class MenuItem {
protected:
	MenuItem (pgmspace_string titulo) :
			titulo(titulo) {
	}
public:
	pgmspace_string titulo;
	virtual unsigned char open () {
		return 0;
	}
	// virtual void operator() = 0; En vez de functor, functionoid ;)
};

#endif /* MENUITEM_H_ */
