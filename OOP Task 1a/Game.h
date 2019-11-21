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
	Game(string name);
	void setup();
	void setPosition();
	void resetGame();
	void processInput(int key);
	vector<vector<char>> prepareGrid();
	bool isRunning() const;
	string get_end_reason() const;
	string getPlayerName() const;
	Mouse getMouse() const;
	Snake getSnake() const;
	int getPlayerScore() const;
	//void saveFile();
	void cheatMode();
	bool isCheatModeActive() const;
	ostream& operator<<(ostream& os);
	//Undo
	void undo();
};
ostream& operator<<(ostream& os, const Game& game);
istream& operator>>(istream& is, Game& game);

