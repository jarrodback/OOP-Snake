#include "MoveableGridItem.h"
#include "Constants.h"

RandomNumberGenerator MoveableGridItem::rng;
MoveableGridItem::MoveableGridItem(char symbol) : GridItem(symbol)
{
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

void MoveableGridItem::randomisePosition() {
	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
}