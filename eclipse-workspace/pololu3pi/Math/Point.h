/*
 * Point.h
 *
 *  Created on: Nov 13, 2012
 *      Author: ninoscript
 */

#ifndef POINT_H_
#define POINT_H_

#include "Math.h"

class Point {
public:
	int8_t x, y;

	Point ();
	Point (int8_t x, int8_t y);

	// Taxicab Geometry
	int8_t taxicabDistanceTo (Point const & objetivo) const;
	Point taxicabDirection () const;

	Point rotated90CW () const;
	Point rotated90CCW () const;

	Point operator- () const;
	Point operator- (const Point &otro) const;
	Point operator+ (const Point &otro) const;
	bool operator== (const Point &otro) const;
	Point operator= (const Point &otro);
	Point operator-= (const Point &otro);
	Point operator+= (const Point &otro);
};

#endif /* POINT_H_ */
