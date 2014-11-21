

#ifndef SHIP_H_
#define SHIP_H_

#include <list>

#include "Block.h"
//#include "Consts.h"

using namespace std;

class Ship {
private:
	list<Block*> blocks;
	Coordinates forstBlockCoords;

public:
	Ship();
	Ship(int);
	virtual ~Ship();
	void setSize(int);
	bool isKilled();
};

#endif /* SHIP_H_ */
