#pragma once

#include "FixedGridItem.h"
#include <cassert>
#include <vector>
#include "constants.h"
#include "Nut.h"

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
	Hole get_hole_no(int no) const;
	bool is_valid_hole_number(int n) const;
	void set_hole_no_at_position(int no, int x, int y);

public:
	Underground();
	void populateHoles();
	bool is_hole_at_position(int x, int y);
	bool hasNutReachedHole(Nut& nut) const;
	char getSymbol() const;
	void moveToAnotherHole(int& x,int& y);


};