#pragma once

#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Snake {
private:
	char symbol;
	int x, y;
	static RandomNumberGenerator rng;
	Mouse* p_mouse;

	void set_direction(int& dx, int& dy);
	void update_position(int dx, int dy);
	bool is_at_position(int x, int y);

	public:
		Snake();
        ~Snake();
		//Getters
		int getX() const;
		int getY() const;
		char getSymbol() const;
		//Setters
		void spot_mouse(Mouse* p_mouse); //sets mouse pointer
		//Logic
		bool has_caught_mouse();
		void chase_mouse();
		void position_at_random();
};