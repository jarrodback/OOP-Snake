#include "Nut.h"
#include "Constants.h"

Nut::Nut() : symbol(NUT)
{
}

Nut::Nut(int x, int y)
	: x(x), y(y), symbol(NUT), collected(false)
{

}
void Nut::positionNut() { x = 10; y = 5; }
void Nut::disappear()
{
	collected = true;
	symbol = FREECELL;
}
int Nut::getX() const { return x; }
int Nut::getY() const { return y; }
char Nut::get_symbol() const { return symbol; }
bool Nut::has_been_collected() { return collected; }
bool Nut::is_at_position(int x, int y) 
{ 
	return is_at_position(getX(), getY()); 
}

