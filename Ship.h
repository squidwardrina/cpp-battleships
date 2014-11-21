

#ifndef SHIP_H_
#define SHIP_H_

#include <list>
#include "Coordinates.h"
#include "Block.h"

using namespace std;

class Ship {
private:
	list<Block*> blocks;

public:
	Ship();
	Ship(int);
	virtual ~Ship();
	void setSize(int);
	void moveTo(Coordinates startCoords);
	bool isKilled();
};

#endif /* SHIP_H_ */
