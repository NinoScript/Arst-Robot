/*
 * point.h
 *
 *  Created on: Nov 12, 2012
 *      Author: lucho
 */

#ifndef POINT_H_
#define POINT_H_

template<typename T>
T abs(T x) {
	return x >= 0 ? x : -x;
}

class point {
public:
	int x, y;
	point() :
			x(0), y(0) {
	}
	point(int x, int y) :
			x(x), y(y) {
	}

	// Taxicab Geometry
	int distancia(point const & objetivo) const {
		point diferencia = *this - objetivo;
		return abs(diferencia.x) + abs(diferencia.y);
	}

	point operator-(const point &otro) const {
		return point(x - otro.x, y - otro.y);
	}

	point operator+(const point &otro) const {
		return point(x + otro.x, y + otro.y);
	}
	point operator-=(const point &otro) {
		x -= otro.x;
		y -= otro.y;
		return *this;
	}

	point operator+=(const point &otro) {
		x += otro.x;
		y += otro.y;
		return *this;
	}

	point operator=(const point &otro) {
		x = otro.x;
		y = otro.y;
		return *this;
	}

	point unitario() {
		return point(this->x > 0 ? 1 : this->x < 0 ? -1 : 0,
				this->y > 0 ? 1 : this->y < 0 ? -1 : 0);
	}

};

#endif /* POINT_H_ */
