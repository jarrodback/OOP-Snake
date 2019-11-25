#include "Nut.h"
#include "Constants.h"
Nut::Nut(int x, int y) :MoveableGridItem(NUT), collected(false)
{
	randomisePosition();
}

void Nut::disappear()
{
	collected = true;
}

bool Nut::has_been_collected() { return collected; }
int Nut::GetX()
{
	return x;
}
int Nut::GetY()
{
	return y;
}
bool Nut::has_been_collected() const { return collected; }

void Nut::respawn() { collected = false; }

ostream& operator<<(ostream& os, const Nut& nut)
{
	if (nut.has_been_collected())
	{
		os << "nut_collected" << endl;
	}
	else
	{
		os << "nut_not_collected" << endl;
		os << nut.getX() << endl;
		os << nut.getY() << endl;
	}
	return os;
}

