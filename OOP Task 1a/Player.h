#pragma once
#include <string>
#include <iostream>
#include "Score.h"
using namespace std;

class Player
{
private:
	string name;
	Score score;
	bool cheating;
	bool cheated;
public:
	Player();
	Player(string name);
	void setName(string name);
	//Query
	string getName() const;
	int getScore() const;
	void updateScore(int amount);
	void toggleCheat();
	void resetCheat();
	bool isCheating() const;
	bool hasCheated() const;
};
ostream& operator<<(ostream& os, const Player& player);
