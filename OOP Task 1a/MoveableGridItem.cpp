#include "MoveableGridItem.h"

MoveableGridItem::MoveableGridItem(char symbol, int x, int y) : GridItem(symbol), x(x), y(y), prevX(x), prevY(y)
{
}
MoveableGridItem::MoveableGridItem(char symbol) : GridItem(symbol), prevX(x), prevY(y)
{
}
bool MoveableGridItem::is_at_position(int x, int y) const
{
	return (this->x == x) && (this->y == y);
}

void MoveableGridItem::setX(int dx)
{
	x = dx;
}

void MoveableGridItem::setY(int dy)
{
	y = dy;
}

void MoveableGridItem::update_position(int dx, int dy)
{
	prevX = x;
	prevY = y;
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

void MoveableGridItem::randomisePosition()
{	
	x = RandomNumberGenerator::getInstance()->get_random_value(SIZE);
	y = RandomNumberGenerator::getInstance()->get_random_value(SIZE);
	prevX = x;
	prevY = y;
}

void MoveableGridItem::setPrevX(int x)
{
	prevX = x;
}

void MoveableGridItem::setPrevY(int y)
{
	prevY = y;
}

int MoveableGridItem::getPrevX() const
{
	return prevX;
}

int MoveableGridItem::getPrevY() const
{
	return prevY;
}

bool MoveableGridItem::isOutOfBounds() const
{
	return (x >= 18 || x <= 2 || y >= 18 || y <= 2);
}
