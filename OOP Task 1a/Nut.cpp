#include "Nut.h"
#include "Constants.h"
Nut::Nut(int x, int y) :FixedGridItem(NUT, x, y), collected(false)
{

}

void Nut::disappear()
{
	collected = true;
}
bool Nut::has_been_collected() { return collected; }

