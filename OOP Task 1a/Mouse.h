#pragma once

#include "constants.h"
#include "Underground.h"

class Mouse
{
private:
	// data members
	const char symbol;
	int  x, y;
	bool alive;
	bool escaped;
	int mouse_dx;
	int mouse_dy;
	// supporting functions 
	void update_position(int dx, int dy);
	bool is_at_position(int x, int y) const;
public:
	// constructor
	Mouse();
	// accessors
	int get_x() const;
	int get_y() const;
	char get_symbol() const;
	bool is_alive() const;
	bool has_escaped() const;
	bool has_reached_a_hole(Underground ug) const;
	// mutators
	void die();
	void escape_into_hole();
	void scamper(int key);
};