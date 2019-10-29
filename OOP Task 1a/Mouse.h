#pragma once

#include "constants.h"
#include "Underground.h"

class Mouse
{
	public:
		// constructor
		Mouse();

		// accessors
		int get_x();
		int get_y();
		char get_symbol() const;
		bool is_at_position(int x, int y);
		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(Underground ug);

		// mutators
		void die();
		void escape_into_hole();
		void scamper(int key);

		char symbol;
		int  x, y;

	private:
		// data members
		bool alive;
		bool escaped;
		int mouse_dx;
		int mouse_dy;

		// supporting functions 
		void position_in_middle_of_grid();
		void update_position(int dx, int dy);
};