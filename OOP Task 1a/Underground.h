#pragma once

#include <cassert>
#include <vector>
#include "constants.h"

using namespace std;

class Hole
{
private:
	// data members
	char symbol;
	int x, y;
public:
	// constructors
	Hole();
	Hole(int x, int y);
	// assessors
	int get_x() const;
	int get_y() const;
	char get_symbol() const;
	bool is_at_position(int x, int y);

};

class Underground
{
private:
	vector<Hole> holes;
	bool is_valid_hole_number(int n) const;
public:
	Underground();
	Hole get_hole_no(int no) const;
	void set_hole_no_at_position(int no, int x, int y);
	vector<Hole> getHoles() const;
};