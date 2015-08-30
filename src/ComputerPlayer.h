/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents the automatic computer player
* 					acts as battleships player in 3 levels
****************************************/

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include <string>
#include <stack>
#include "Consts.h"
#include "Coordinates.h"
#include "Player.h"

class ComputerPlayer: public Player {
private:
	ComputerLevel level; // the computer level

	// Phrases computer says
	vector<std::string> phrasesOnMyHit;
	vector<std::string> phrasesOnEnemyHit;
	vector<std::string> phrasesOnEnemyMiss;

	// Utils for guessing
	stack<Coordinates> futureHits;
	vector<Coordinates> oldGuesses;
	bool movingDiagRight;
	bool hasMoreIdeas;
	int smartX;
	int smartY;

	void pushNeighbours(Coordinates& guess); // saves all near coords for future guesses
	bool isNewGuess(const Coordinates candidate); // checks if the guess in new
	Coordinates* getRandomGuess(); // returns random new guess
	Coordinates* strategicMove(); // return new strategic guess
	Coordinates* guessNextShipBlock(); // returns new guess from future guesses saved
	void initPhrases(); // inits phrases for computer

	// computer speaks:
	void yellOnEnemyMiss();
	void yellOnEnemyHit();
	void yellOnMyHit();

public:
	ComputerPlayer(string name);
	virtual ~ComputerPlayer();

	Coordinates * makeGuess(); // computer makes guess
	void placeShip(int); // computer places the ship
	HitStatus handleAttack(const Coordinates&); // handle incoming attack
	void sendHitFeedback(Coordinates, HitStatus&); // get hit feedback and take care of it
};

#endif /* COMPUTERPLAYER_H_ */
