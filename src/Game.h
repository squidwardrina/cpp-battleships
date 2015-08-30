/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents the game class
* 					responsible for the major game logic
* 					independently of the game mood
****************************************/

#ifndef GAME_H_
#define GAME_H_

#include <string>

#include "Player.h"

/*
 *
 */
class Game {
protected:
	Player * player1;
	Player * player2;
	bool isPlayer1Turn;
	void showTurn(string, Coordinates&, HitStatus&);

public:
	Game();
	virtual ~Game();

	virtual void playOneTurn(); // runs one turn in the game
	virtual void drawBoards() = 0;
	void placeShips(); // places both player's ships
	bool isOver(); // checks if the game is over
	string getWinnerName(); // gets the name of the winner or NULL
};

#endif /* GAME_H_ */
