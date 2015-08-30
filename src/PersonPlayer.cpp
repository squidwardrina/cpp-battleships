/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description: represents the person player in the game
****************************************/

#include "PersonPlayer.h"

#include <cctype>
#include <iostream>
#include "Coordinates.h"
#include <cstdlib>

#define EMPTY_SIGN '~'
#define HIT_SIGN 'x'
#define MISS_SIGN 'o'
#define KILL_SIGN 'K'

PersonPlayer::PersonPlayer(string name)  : Player(name) {
	// Init the empty enemy sketch
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			enemySketch[i][j] = EMPTY_SIGN;
		}
	}
}

PersonPlayer::~PersonPlayer() {}

/*************************************************************************
* Function name: strToInt
* The Input: string
* The output: integer or -1 if impossible to convert
* The Function gets int from string. If impossible returns -1
*************************************************************************/
int PersonPlayer::strToInt(const string str) {
	if (str.length() == 0) {
		return -1;
	}

	// Go over the string's chars and validate
	int result = 0;
	for (unsigned int i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i])) {
			return -1; // Not a digit - validation fails
		}
		result *= 10;
		result += str[i] - 48; // 48 is ascii value of 0
	}

	return result;
}

/*************************************************************************
* Function name: getCoordinate
* The Input: -
* The output: valid coordinate got from user
* The Function operation: recieves coordinate from user and validates it
*************************************************************************/
int PersonPlayer::getCoordinate() {
	string str;
	cin >> str;

	// Validate until we get right input
	int result = strToInt(str);

	while (result == -1) {
		cout << "Wrong input. Try again:";
		cin >> str;
	}
	return result;
}

/*************************************************************************
* Function name: makeGuess
* The Input: -
* The output: guess coordinates
* The Function operation: recieves a valid guess from user
*************************************************************************/
Coordinates* PersonPlayer::makeGuess() {
	cout << "Make a guess.\nEnter 'x' coordinate: ";
	int x = getCoordinate();
	cout << "Enter 'y' coordinate: ";
	int y = getCoordinate();
	return new Coordinates(x, y);
}

/*************************************************************************
* Function name: placeShip
* The Input: ship type
* The output: -
* The Function operation: handles placing the spec. ship by user's coordinates choice
*************************************************************************/
void PersonPlayer::placeShip(int shipType) {
	// Get coorinates from user
	cout << "Here's your board for now:\n";
	board->draw();
	cout << "\nLets place the ship that has the following shape:\n";
	Ship ship;
	ship.draw(shipType);
	cout << "\nEnter coordinate x: ";
	int x = getCoordinate();
	cout << "Enter coordinate y: ";
	int y = getCoordinate();

	// Try to place a ship on the specified coords
	Coordinates * coords = new Coordinates(x, y);
	ship = Ship(shipType, *coords);

	// Try again until user enters a suitable place on the board
	while (!canPlaceShip(ship)) {
		cout << "\tImpossible position. Try again:\nCoordinate x: ";
		int x = getCoordinate();
		cout << "Coordinate y: ";
		int y = getCoordinate();
		coords->setX(x);
		coords->setY(y);
		ship = Ship(shipType, *coords);
	}

	// Add the ship to the board
	board->addShip(shipType, coords);
}

/*************************************************************************
* Function name: sendHitFeedback
* The Input: the guess and the result status
* The output: -
* The Function operation: saves the previous guess information
*************************************************************************/
void PersonPlayer::sendHitFeedback(Coordinates guess, HitStatus& status) {
	int x = guess.getX();
	int y = guess.getY();

	// Add the coordinates info to enemy's board sketch
	switch (status) {
	case MISS:
		enemySketch[x][y] = MISS_SIGN;
		break;

	case HIT:
		enemySketch[x][y] = HIT_SIGN;
		break;

	case KILL:
		enemySketch[x][y] = KILL_SIGN;
		break;

		default:
			break;
	}
}

/*************************************************************************
* Function name: drawEnemySketch
* The Input: -
* The output: -
* The Function operation: draws the sketch of enemie's board as seen by user
*************************************************************************/
void PersonPlayer::drawEnemySketch() {
	// Print the columns numbers
	cout << "  ";
	for (int i = 0; i < BOARD_SIZE; ++i) {
		cout << i << " "; // just the columns' numbers
	}

	// Print rows numbers and each row
	for (int i = 0; i < BOARD_SIZE; ++i) {
		cout << "\n" << i << " "; // row's number
		for (int j = 0; j < BOARD_SIZE; ++j) {
			cout << enemySketch[i][j] << " ";
		}
	}
}
