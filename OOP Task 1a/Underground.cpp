#include "Underground.h"

Hole::Hole() : FixedGridItem(HOLE)
{

}
Hole::Hole(int x, int y) : FixedGridItem(HOLE, x, y)
{
}

// number of holes in underground
static const int MAXHOLES(3);

Underground::Underground() :  holes(MAXHOLES)
{
}

Hole Underground::get_hole_no(int no) const
{
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	return holes.at(no);
}

void Underground::set_hole_no_at_position(int no, int x, int y)
{
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));
	holes.push_back(Hole(x, y));
}

bool Underground::is_valid_hole_number(int no) const
{
	return no >= 0 && no < (int)holes.size();
}

vector<Hole> Underground::getHoles() const
{
	return holes;
}
