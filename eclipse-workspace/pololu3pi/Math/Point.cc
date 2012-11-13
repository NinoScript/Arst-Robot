/*
 * Point.cc
 *
 *  Created on: Nov 12, 2012
 *      Author: ninoscript
 */

#include "Point.h"

Point::Point () :
		x(0),
		y(0) {
}
Point::Point (int8_t x, int8_t y) :
		x(x),
		y(y) {
}

// Taxicab Geometry
int8_t Point::TaxicabDistanceTo (Point const & objetivo) const {
	Point diferencia = *this - objetivo;
	return abs(diferencia.x) + abs(diferencia.y);
}

Point Point::operator- (const Point &otro) const {
	return Point(x - otro.x, y - otro.y);
}

Point Point::operator+ (const Point &otro) const {
	return Point(x + otro.x, y + otro.y);
}

Point Point::operator-= (const Point &otro) {
	x -= otro.x;
	y -= otro.y;
	return *this;
}

Point Point::operator+= (const Point &otro) {
	x += otro.x;
	y += otro.y;
	return *this;
}

Point Point::operator= (const Point &otro) {
	x = otro.x;
	y = otro.y;
	return *this;
}
