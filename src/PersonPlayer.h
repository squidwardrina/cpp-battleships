/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description: represents the person player in the game
****************************************/

#ifndef PERSONPLAYER_H_
#define PERSONPLAYER_H_

#include <string>

#include "Board.h"
#include "Consts.h"
#include "Player.h"

using namespace std;

class PersonPlayer: public Player {
private:
	char enemySketch[BOARD_SIZE][BOARD_SIZE];
	int strToInt(const string);
	int getCoordinate();

public:
	PersonPlayer(string name);
	virtual ~PersonPlayer();

	Coordinates * makeGuess(); // person makes guess
	void placeShip(int); // person places his ship by type
	void sendHitFeedback(Coordinates, HitStatus&); // recieves feedback on the attack
	void drawEnemySketch(); // draws the sketch of the enemie's board
};

#endif /* PERSONPLAYER_H_ */
