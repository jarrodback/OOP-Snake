#include "GridItem.h"

GridItem::GridItem(char symbol) : symbol(symbol)
{
}

char GridItem::getSymbol() const
{
	return symbol;
}

/////////////MOVEABLE/////////////
bool MoveableGridItem::is_at_position(int x, int y) const
{
	return (this->x == x) && (this->y == y);
}

void MoveableGridItem::update_position(int dx, int dy)
{
	x += dx;
	y += dy;
}

int MoveableGridItem::getX() const
{
	return x;
}

int MoveableGridItem::getY() const
{
	return y;
}
/////////////FIXED/////////////
bool FixedGridItem::is_at_position(int x, int y) const
{
	return (this->x == x) && (this->y == y);
}

int FixedGridItem::getX() const
{
	return x;
}

int FixedGridItem::getY() const
{
	return y;
}
