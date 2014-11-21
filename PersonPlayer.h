

#ifndef PERSONPLAYER_H_
#define PERSONPLAYER_H_

#include <string>
#include "Player.h"

class PersonPlayer: public Player {
public:
	PersonPlayer();
	virtual ~PersonPlayer();
	Coordinates * makeGuess();

private:
	int strToInt(const string& str);
	int getCoordinate();
	bool handleAttack(Coordinates hitCoordinates);
};

#endif /* PERSONPLAYER_H_ */
