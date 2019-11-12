#pragma once

#include "FixedGridItem.h"
#include <cassert>
#include <vector>
#include "constants.h"

using namespace std;

class Hole : public FixedGridItem
{
public:
	Hole();
	// constructors
	Hole(int x, int y);
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