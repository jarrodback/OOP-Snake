#include "Underground.h"
// number of holes in underground
static const int MAXHOLES(3);

Underground::Underground() : holes()
{
}

Hole Underground::get_hole_no(int no) const
{
	assert(is_valid_hole_number(no));
	return holes.at(no);
}

void Underground::set_hole_no_at_position(int no, int x, int y)
{
	assert(is_valid_hole_number(no));
	holes.push_back(Hole(x, y));
}

void Underground::populateHoles()
{
	set_hole_no_at_position(0, 4, 3);
	set_hole_no_at_position(1, 15, 10);
	set_hole_no_at_position(2, 7, 15);
}

bool Underground::is_hole_at_position(int x, int y)
{
	for (Hole hole : holes)
		if (hole.is_at_position(x, y)) return true;
	return false;
}

bool Underground::is_valid_hole_number(int no) const
{
	return no >= 0 && no < MAXHOLES;
}

bool Underground::hasNutReachedHole(Nut& nut) const
{
	for (Hole h : holes)
	{
		if (nut.is_at_position(h.getX(), h.getY())) return true;
	}
	return false;
}

char Underground::getSymbol() const
{
	return HOLE;
}

void Underground::moveToAnotherHole(int& x, int& y)
{
	int holeX = x;
	int holeY = y;
	int holeNum = RandomNumberGenerator::getInstance()->get_random_value(3) - 1;
	while (holes.at(holeNum).is_at_position(holeX, holeY))
	{
		holeNum = RandomNumberGenerator::getInstance()->get_random_value(3) - 1;
	}
	x = holes.at(holeNum).getX();
	y = holes.at(holeNum).getY();
}
