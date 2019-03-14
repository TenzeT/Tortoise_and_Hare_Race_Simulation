/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-13-2019
Description: File containing definitions for the functions of the Race.h header file
*/

#include "stdafx.h"
#include "Race.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

Race::Race()
	: tortoiseLocation_(0),
	  tortoiseTempLocation_(0),
	  hareLocation_(0),
	  hareTempLocation_(0)
{
	using std::cout;
	using std::endl;
	
	// Initialize empty race line
	for (size_t i = 0; i < RACE_LINE_SIZE; ++i)
		raceLine_[i] = "-";

	cout << "And they're off!" << endl;

	srand(static_cast<unsigned int>(time(0)));
	
}

Race::~Race() {}

void Race::runRace() {

	for (;;) {
		moveTortoise(&tortoiseLocation_);
		moveHare(&hareLocation_);

		// If tortoise won
		if (tortoiseLocation_ >= RACE_LINE_SIZE) {
			raceLine_[RACE_LINE_SIZE - 1] = "T";
			std::cout << "The tortoise won" << std::endl;
			break;
		}

		// Hare won
		if (hareLocation_ >= RACE_LINE_SIZE) {
			raceLine_[RACE_LINE_SIZE - 1] = "H";
			std::cout << "The hare won" << std::endl;
			break;
		}

		// Edge cases
		if (tortoiseLocation_ < 1)
			tortoiseLocation_ = 1;

		if (hareLocation_ < 1)
			hareLocation_ = 1;

		// Landed on same spot - tortoise bites hare
		if (tortoiseLocation_ == hareLocation_) {
			raceLine_[tortoiseTempLocation_] = "-";
			raceLine_[hareTempLocation_] = "-";
			raceLine_[hareLocation_] = "X";
			continue;
		}

		// Else update race line
		raceLine_[tortoiseTempLocation_] = "-";
		raceLine_[tortoiseLocation_] = "T";
		raceLine_[hareTempLocation_] = "-";
		raceLine_[hareLocation_] = "H";

		printRaceLine(raceLine_);
		
	}
	
	
}

void Race::moveTortoise(int *tortLocation) {
	
	int numSteps = calculateMoves(Animals::TORTOISE);

	tortoiseTempLocation_ = *tortLocation;
	*tortLocation += numSteps;
}

void Race::moveHare(int *hareLocation) {

	int numSteps = calculateMoves(Animals::HARE);

	hareTempLocation_ = *hareLocation;
	*hareLocation += numSteps;
}

int Race::calculateMoves(enum Animals animal) const {

	int stepsToMove = 0;
	unsigned int randNum = 1 + rand() % 100;

	switch (animal) {
		case Animals::TORTOISE:
			if (randNum > 0 && randNum <= 50)
				stepsToMove = 3;
			else if (randNum > 50 && randNum <= 70)
				stepsToMove = -6;
			else
				stepsToMove = 1;
			break;
		case Animals::HARE:
			if (randNum > 0 && randNum <= 20)
				stepsToMove = 0;
			else if (randNum > 20 && randNum <= 40)
				stepsToMove = 9;
			else if (randNum > 40 && randNum <= 50)
				stepsToMove = -12;
			else if (randNum > 50 && randNum <= 80)
				stepsToMove = 1;
			else
				stepsToMove = -2;
			break;
		default:
			std::cout << "Default hit" << std::endl;
	}
	
	return stepsToMove;
}

void Race::printRaceLine(std::string raceLine[]) const {
	
	for (size_t i = 0; i < RACE_LINE_SIZE; ++i) {
		std::cout << *(raceLine_ + i);
	}

	std::cout << std::endl;
}