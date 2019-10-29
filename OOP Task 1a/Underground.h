#pragma once

#include <cassert>
#include <vector>

#include "constants.h"

using namespace std;

class Hole
{
	public:
		// constructors
		Hole();
		Hole(int x, int y);

		// assessors
		int get_x();
		int get_y();
		char get_symbol() const;
		bool is_at_position(int x, int y);

	private:
		// data members
		char symbol;
		int x, y;
};

class Underground
{
	public:
		Underground();
		Hole get_hole_no(int no) const;
		void set_hole_no_at_position(int no, int x, int y);
		bool is_valid_hole_number(int n) const;
		vector<Hole> holes;
};