#pragma once

#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Snake {
private:
	char symbol;
	int x, y;
	RandomNumberGenerator rng;
	public:
		Snake();
        ~Snake();
		//Getters
		int getX() const;
		int getY() const;
		char getSymbol() const;

		bool is_at_position(int x, int y);  
		bool has_caught_mouse() ;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void set_direction(int& dx, int& dy);
		void position_at_random();
		void update_position(int dx, int dy);

		Mouse* p_mouse;
};