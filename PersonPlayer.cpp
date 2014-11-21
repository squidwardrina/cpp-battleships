/*
 * PersonPlayer.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#include <string>
#include <iostream>
#include "Consts.h"
#include "PersonPlayer.h"

PersonPlayer::PersonPlayer() {
}

PersonPlayer::~PersonPlayer() {
}

int PersonPlayer::strToInt(const string& str) {
	if (str.length() == 0 || str[0] == '0')
	{
		return -1;
	}

	// Go over the string's chars and validate
	int result = 0;
	for (unsigned int i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i])) {
			// Not a digit - validation fails
			return -1;
		}
		result *= 10;
		result += str[i] + 48; // ascii value of 0
	}

	return result;
}

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

Coordinates* PersonPlayer::makeGuess() {
	cout << "Make a guess.\nEnter 'x' coordinate: ";
	int x = getCoordinate();
	cout << " Enter 'y' coordinate: ";
	int y = getCoordinate();
	return new Coordinates(x, y);
}

bool PersonPlayer::handleAttack(Coordinates hitCoordinates) {
}
