#pragma once

#include <string>		
#include <assert.h>	
#include <vector>
#include <fstream>

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "Nut.h"
#include "Player.h"

using namespace std;

class Game
{
private:
	Mouse mouse;
	Snake snake;
	Underground underground;
	Nut nut;
	Player player;

	void apply_rules();

public:
	Game();
	Game(string name);

	vector<vector<char>> prepareGrid();

	string get_end_reason() const;
	string getPlayerName() const;
	int getPlayerScore() const;
	bool isCheatModeActive() const;
	bool isRunning() const;

	Mouse& getMouse();
	Snake& getSnake();
	Nut& getNut();
	Player& getPlayer();

	void setup();
	void setPosition();
	void resetGame();
	void processInput(int key);
	void undo();
	void cheatMode();
};
ostream& operator<<(ostream& os, Game& game);
istream& operator>>(istream& is, Game& game);