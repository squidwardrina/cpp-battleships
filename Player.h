/****************************************
* Student Name:		Rina Fridland
* Exercise Name:
* File description:
****************************************/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Board.h"
#include "Coordinates.h"

class Player {
private:
	Board* board;

public:
	Player();
	virtual ~Player();
	virtual Coordinates * makeGuess() = 0;
	virtual bool handleAttack(Coordinates) = 0;
};

#endif /* PLAYER_H_ */
