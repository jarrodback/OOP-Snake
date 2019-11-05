#pragma once

#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Snake {
private:
	const char symbol;
	int x, y;
	static RandomNumberGenerator rng;
	Mouse* p_mouse;

	void set_direction(int& dx, int& dy) const;
	void update_position(int dx, int dy);
	bool is_at_position(int x, int y) const;

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
		bool has_caught_mouse() const;
		void chase_mouse();
		void position_at_random();
};