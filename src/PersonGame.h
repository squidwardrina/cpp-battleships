/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents the game class
* 					Responsible for running the battleships game logic,
* 					in mode "computer vs. player"
****************************************/

#ifndef PERSONGAME_H_
#define PERSONGAME_H_

#include "Game.h"

class PersonGame: public Game {
private:
	void showTurn(Coordinates&, HitStatus&);

public:
	PersonGame();
	virtual ~PersonGame();
	void drawBoards(); // draws the boards
};

#endif /* PERSONGAME_H_ */
