#include "Nut.h"
#include "Constants.h"

Nut::Nut()
{
}

Nut::Nut(int x, int y)
	: x(x), y(y), symbol(NUT), collected(true)
{

}
void Nut::positionNut() { x = 10; y = 5; }
int Nut::get_x() const { return x; }
int Nut::get_y() const { return y; }
char Nut::get_symbol() const { return symbol; }
bool Nut::has_been_collected() { return collected; }
bool Nut::is_at_position(int x, int y) { return is_at_position(get_x(), get_y()); }
void Nut::disappear() {
	if (mouse1->get_x() == get_x() && mouse1->get_y() == get_y())
	{
		get_symbol() == FREECELL;
	}
}

