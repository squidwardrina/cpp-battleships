/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	responsible for the game logic "comp. vs. comp."
****************************************/

#ifndef COMPUTERGAME_H_
#define COMPUTERGAME_H_

#include "Game.h"

/*
 *
 */
class ComputerGame: public Game {
public:
	ComputerGame();
	virtual ~ComputerGame();
	void drawBoards(); // draws both computer boards
	void playOneTurn();
};

#endif /* COMPUTERGAME_H_ */
