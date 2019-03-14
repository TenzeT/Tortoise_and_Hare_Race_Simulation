/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-13-2019
Description: The header file for the Race class - includes function declarations
*/

#pragma once
#include <string>

class Race {
public:
	Race();
	~Race();
	void runRace();

private:
	enum Animals { TORTOISE, HARE };
	static const int RACE_LINE_SIZE = 70;
	std::string raceLine_[RACE_LINE_SIZE];
	int tortoiseLocation_;
	int tortoiseTempLocation_;
	int hareLocation_;
	int hareTempLocation_;

	void moveTortoise(int *);
	void moveHare(int *);
	int calculateMoves(enum Animals) const;
	void printRaceLine(std::string []) const;
};