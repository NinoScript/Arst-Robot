/*
 * Binder.h
 *
 *  Created on: Nov 13, 2012
 *      Author: ninoscript
 */

#ifndef BINDER_H_
#define BINDER_H_

class Caller {
public:
	virtual void call() {}
protected:
	Caller () {}
};

template<typename T, void (T::*method)()>
class Binder : public Caller {
public:
	Binder(T & object) : object(object) {}
	void call () {
		(object.*method)();
	}
private:
	T & object;
};

#endif /* BINDER_H_ */
