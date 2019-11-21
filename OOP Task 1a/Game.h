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
	int find_hole_number_at_position(int x, int y) const;

	

public:
	Game();
	Game(string name);
	void setup();
	void setPosition();
	void resetGame();
	void processInput(int key);
	vector<vector<char>> prepareGrid();
	bool isRunning() const;
	string get_end_reason() const;
	string getPlayerName() const;
	Mouse& getMouse();
	Snake& getSnake();
	Nut& getNut();
	Player& getPlayer();
	int getPlayerScore() const;
	//void saveFile();
	void cheatMode();
	bool isCheatModeActive() const;
};
ostream& operator<<(ostream& os, Game& game);
istream& operator>>(istream& is, Game& game);

