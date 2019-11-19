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

void Nut::respawn() { collected = false; }


