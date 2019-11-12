#pragma once

#include <string>		
#include <assert.h>	
#include <vector>

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "Nut.h"

using namespace std;

class Game
{
private:
	Mouse mouse;
	Snake snake;
	Underground underground;
	Nut nut;

	void apply_rules();
	int find_hole_number_at_position(int x, int y) const;

public:
	Game();
	void set_up();
	void process_input(int key);
	vector<vector<char>> prepare_grid();
	bool is_running() const;
	string get_end_reason() const;
};