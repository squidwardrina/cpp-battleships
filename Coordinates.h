/*
 * Coordinates.h
 *
 *  Created on: Nov 19, 2014
 *      Author: rina
 */

#ifndef COORDINATES_H_
#define COORDINATES_H_

/*
 *
 */
class Coordinates {
protected:
	int x;
	int y;

public:
	Coordinates(int, int);
	virtual ~Coordinates();

	int getX() const {
		return x;
	}

	void setX(int x) {
		this->x = x;
	}

	int getY() const {
		return y;
	}

	void setY(int y) {
		this->y = y;
	}
};

#endif /* COORDINATES_H_ */
