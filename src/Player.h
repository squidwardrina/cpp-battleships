/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description: represents a simple player
* 					abstract
****************************************/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "Ship.h"
#include "Board.h"

class Coordinates;

using namespace std;

class Player {
protected:
	Board* board;
	string name;

	bool canPlaceShip(Ship&);

public:
	Player(string);
	virtual ~Player();

	virtual Coordinates * makeGuess() = 0;
	virtual HitStatus handleAttack(const Coordinates&); // handles incoming attack
	void drawBoard(); // draws the player's board
	void placeShips(); // places the ships for the player
	virtual void placeShip(int) = 0;
	bool isDestroyed(); // checks if the player is dead
	virtual void sendHitFeedback(Coordinates, HitStatus&) = 0;
	const string& getName() const {
		return name;
	}
};

#endif /* PLAYER_H_ */
