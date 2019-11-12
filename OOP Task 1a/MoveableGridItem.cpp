#include "MoveableGridItem.h"
MoveableGridItem::MoveableGridItem(char symbol) : GridItem(symbol)
{
	x = 0; y = 0;
}

bool MoveableGridItem::is_at_position(int x, int y) const
{
	return (this->x == x) && (this->y == y);
}

void MoveableGridItem::SetX(int dx)
{
	x = dx;
}

void MoveableGridItem::SetY(int dy)
{
	y = dy;
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