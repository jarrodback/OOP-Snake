#pragma once
#include <string>
#include <iostream>
#include "Score.h"
using namespace std;

class Player
{
private:
	const string name;
	Score score;
public:
	Player();
	//Query
	string getName() const;
	int getScore() const;
	void updateScore(int amount);
};

