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
	void set_up();
	void process_input(int key);
	vector<vector<char>> prepare_grid();
	bool is_running() const;
	string get_end_reason() const;
	string getPlayerName() const;
	int getPlayerScore() const;
	void readFile();
	void writeFile();
};