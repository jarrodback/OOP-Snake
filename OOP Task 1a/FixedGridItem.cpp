#include "FixedGridItem.h"
FixedGridItem::FixedGridItem(char symbol, int x, int y) : GridItem(symbol), x(x), y(y)
{
}

FixedGridItem::FixedGridItem(char symbol) : GridItem(symbol), x(0), y(0)
{
}

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