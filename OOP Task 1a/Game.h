#pragma once

#include <string>		
#include <assert.h>	
#include <vector>

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"

using namespace std;

class Game
{
private:
	Mouse mouse;
	Snake snake;
	Underground underground;

 public:
      void set_up();
      void process_input(int key);
      vector<vector<char>> prepare_grid();
      void apply_rules();
      bool is_running() const;
      int find_hole_number_at_position(int x, int y) const;
      string get_end_reason();
};