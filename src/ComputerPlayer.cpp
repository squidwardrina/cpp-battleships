/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents the automatic computer player
* 					acts as battleships player, has 3 levels
****************************************/

#include "ComputerPlayer.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iterator>
#include <vector>

#include "Board.h"
#include "Coordinates.h"
#include "GameMenu.h"
#include "Ship.h"

ComputerPlayer::ComputerPlayer(std::string name) : Player(name) {
	srand(time(0)); // set the random seed
	movingDiagRight = true;
	hasMoreIdeas = true;
	smartX = -1;
	smartY = -1;
	initPhrases();

	// Chose level for this computer
	GameMenu menu;
	this->level = menu.getLevelFor(name);
}

ComputerPlayer::~ComputerPlayer() {}

void ComputerPlayer::initPhrases() {
	phrasesOnMyHit.push_back("Hahaa, got you! =P");
	phrasesOnMyHit.push_back("Yeeeahhh I'n winning!=))");
	phrasesOnMyHit.push_back("YEAH! Join the dark side!");
	phrasesOnMyHit.push_back("Evil will always prevail, because good is dumb.");
	phrasesOnMyHit.push_back("Hahaa oh I'm a genius.");

	phrasesOnEnemyHit.push_back("Oh no! My revenge would be sour...");
	phrasesOnEnemyHit.push_back("You'll regret it.");
	phrasesOnEnemyHit.push_back("Damn! =(");
	phrasesOnEnemyHit.push_back("What... How?! =(");

	phrasesOnEnemyMiss.push_back("Hahaaa! So close! =P");
	phrasesOnEnemyMiss.push_back("Go play volleyball.");
	phrasesOnEnemyMiss.push_back("Nope, it's not your day.");
	phrasesOnEnemyMiss.push_back("LOooOOoOoOOoserrr!=))");
}

/*************************************************************************
* Function name: getRandomGuess
* The Input: -
* The output: guess coordinates
* The Function operation: generates random guess
*************************************************************************/
Coordinates* ComputerPlayer::getRandomGuess() {
	int x, y;
	// Randomize x and y until we get new guess
	do {
		x = rand() % 10;
		y = rand() % 10;
	} while (!isNewGuess(Coordinates(x, y)));
	return new Coordinates(x, y);
}

/*************************************************************************
* Function name: strategicMove
* The Input: -
* The output: guess coordinates
* The Function operation: generates strategic guess
*************************************************************************/
Coordinates* ComputerPlayer::strategicMove() {
	/* Running in diagonals.
	 * first - 3 right ones, then 3 left ones.
	 * after that (if the enemy survived) - random moves.
	 */
	if (!hasMoreIdeas) {
		return getRandomGuess();
	}

	do {
		// Running in diagonals right
		if (movingDiagRight) {
			smartX++;
			smartY++;
			// The first (major) diagonal is over
			if (smartX == BOARD_SIZE && smartY == BOARD_SIZE) {
				smartX = 0;
				smartY = BOARD_SIZE / 2;

			// The first small diagonal is over
			} else if (smartY == BOARD_SIZE) {
				smartX = BOARD_SIZE / 2;
				smartY = 0;

			// The second small diagonal is over
			} else if (smartX == BOARD_SIZE) {
				movingDiagRight = false;
				smartX = 0;
				smartY = BOARD_SIZE - 1;
			}

		// Running diagonally left
		} else {
			smartX++;
			smartY--;
			// The first (major) diagonal is over
			if (smartX == BOARD_SIZE && smartY == 0) {
				smartX = 0;
				smartY = (BOARD_SIZE / 2) + 1;

			// The first small diagonal is over
			} else if (smartY == 0) {
				smartX = (BOARD_SIZE / 2) - 2;
				smartY = BOARD_SIZE - 1;

			// The second small diagonal is over
			} else if (smartX == BOARD_SIZE) {
				hasMoreIdeas = false;
				return getRandomGuess();
			}
		}
		// If this guess was already made - continue
	} while (!isNewGuess(Coordinates(smartX, smartY)));
	return new Coordinates(smartX, smartY);
}

/*************************************************************************
* Function name: guessNextShipBlock
* The Input: -
* The output: guess coordinates
* The Function operation: gets the next possible enemy ship coordinates
*************************************************************************/
Coordinates* ComputerPlayer::guessNextShipBlock() {
	// Get next guess from the guesses stack
	Coordinates* guess = new Coordinates(
			futureHits.top().getX(), futureHits.top().getY());
	futureHits.pop();
	return guess;
}

/*************************************************************************
* Function name: makeGuess
* The Input: -
* The output: guess coordinates
* The Function operation: generates automatic guess according to computer level
*************************************************************************/
Coordinates * ComputerPlayer::makeGuess() {
	Coordinates * guess;
	switch (level) {
	case EASY: // easy level - random guesses
		guess = getRandomGuess();
		break;

	case MEDIUM: // medium level - upon hit destroys the ship
		if (futureHits.empty()) {
			guess = getRandomGuess();
		} else {
			guess = guessNextShipBlock();
		}
		oldGuesses.push_back(*guess);
		break;

	case HARD: // hard level - strategic movements
		if (futureHits.empty()) {
			guess = strategicMove();
		} else {
			guess = guessNextShipBlock();
		}
		oldGuesses.push_back(*guess);
		break;

	default:
		guess = getRandomGuess();
		break;
	}
	return guess;
}

/*************************************************************************
* Function name: placeShip
* The Input: ship type
* The output: -
* The Function operation: places a ship of the spec. type on the player's board
*************************************************************************/
void ComputerPlayer::placeShip(int shipType) {
	// Generate random coordinates and try to create a ship there
	int x = rand() % 10;
	int y = rand() % 10;
	Coordinates * coords = new Coordinates(x, y);
	Ship ship = Ship(shipType, *coords);

	// Try again until we find a suitable place on the board
	while (!canPlaceShip(ship)) {
		coords->setX(rand() % 10);
		coords->setY(rand() % 10);
		ship = Ship(shipType, *coords);
	}

	// Add the ship to the board
	board->addShip(shipType, coords);
}

/*************************************************************************
* Function name: isNewGuess
* The Input: guess coords
* The output: true if this coordinates were never tried before
* The Function operation: checks if this coordinates were never tried before
*************************************************************************/
bool ComputerPlayer::isNewGuess(const Coordinates candidate) {
	std::vector<Coordinates>::iterator oldGuess;

	// Check if the guess was made already
	for (oldGuess = oldGuesses.begin(); oldGuess != oldGuesses.end(); ++oldGuess) {
		if (oldGuess->getX() == candidate.getX() &&
				oldGuess->getY() == candidate.getY()) {
			return false;
		}
	}
	return true;
}

/*************************************************************************
* Function name: pushNeighbours
* The Input: guess coords
* The output: -
* The Function operation: saves all the neighbour coordinates of this guess
* 							to be guessed later (to reveal the hit ship)
*************************************************************************/
void ComputerPlayer::pushNeighbours(Coordinates& guess) {
	// Go down
	Coordinates candidate = Coordinates(guess.getX() + 1, guess.getY());
	if (isNewGuess(candidate) && candidate.getX() < BOARD_SIZE) {
		futureHits.push(candidate);
	}

	// Go right
	candidate = Coordinates(guess.getX(), guess.getY() + 1);
	if (isNewGuess(candidate) && candidate.getY() < BOARD_SIZE) {
		futureHits.push(candidate);
	}

	// Go up
	candidate = Coordinates(guess.getX() - 1, guess.getY());
	if (isNewGuess(candidate) && candidate.getX() > 0) {
		futureHits.push(candidate);
	}

	// Go left
	candidate = Coordinates(guess.getX(), guess.getY() - 1);
	if (isNewGuess(candidate) && candidate.getY() > 0) {
		futureHits.push(candidate);
	}
}

/*************************************************************************
* Function name: yellOnMyHit
* The Input: -
* The output: -
* The Function operation: computer talks
*************************************************************************/
void ComputerPlayer::yellOnMyHit() {
	// Yell something offensive:
	int i = rand() % phrasesOnMyHit.size();
	cout << "\n>>>>>>>>>\t" << name << " says: " << phrasesOnMyHit[i] << "\n";
}

/*************************************************************************
* Function name: yellOnEnemyMiss
* The Input: -
* The output: -
* The Function operation: computer talks
*************************************************************************/
void ComputerPlayer::yellOnEnemyMiss() {
	// Yell something offensive:
	int i = rand() % phrasesOnEnemyMiss.size();
	cout << "\n>>>>>>>>>\t" << name << " says: " << phrasesOnEnemyMiss[i] << "\n";
}

/*************************************************************************
* Function name: yellOnEnemyHit
* The Input: -
* The output: -
* The Function operation: computer talks
*************************************************************************/
void ComputerPlayer::yellOnEnemyHit() {
	// Yell something offensive:
	int i = rand() % phrasesOnEnemyHit.size();
	cout << "\n>>>>>>>>>\t" << name << " says: " << phrasesOnEnemyHit[i] << "\n";
}

/*************************************************************************
* Function name: handleAttack
* The Input: coordinates
* The output: the attack status - hit miss or kill
* The Function operation: handles the attack on these coords
*************************************************************************/
HitStatus ComputerPlayer::handleAttack(const Coordinates& coords) {
	HitStatus status = board->fireAt(coords);
	switch (status) {
	case HIT:
	case KILL:
		yellOnEnemyHit();
		break;

	case MISS:
		yellOnEnemyMiss();
		break;
		default:
			break;
	}
	return status;
}

/*************************************************************************
* Function name: sendHitFeedback
* The Input: coordinates of the guess and the result of attack
* The output: -
* The Function operation: gets feedback on the guess and saves the results
* 							for future guesses
*************************************************************************/
void ComputerPlayer::sendHitFeedback(Coordinates guess, HitStatus& status) {
	switch (status) {
	case KILL: // the ship is destroyed. Forget all future guesses
		while (!futureHits.empty()) {
			futureHits.pop();
		}
		yellOnMyHit(); // say something
		break;

	case HIT: // continue destroying the ship
		pushNeighbours(guess);
		yellOnMyHit(); // say something
		break;

	case MISS: // fail.
		break;
	default:
		break;
	}

}
