#pragma once
#include "GridItem.h"
#include "RandomNumberGenerator.h"

class MoveableGridItem : public GridItem
{
protected:
	int x, y, prevX, prevY;
	static RandomNumberGenerator rng;
public:
	MoveableGridItem(char symbol);
	void update_position(int dx, int dy);
	MoveableGridItem(char symbol, int x, int y);
	bool is_at_position(int x, int y) const;

	void randomisePosition();

	//GetSet
	void setX(int dx);
	void setY(int dy);
	int getX() const;
	int getY() const;
	void setPrevX(int x);
	void setPrevY(int y);
	int getPrevX() const;
	int getPrevY() const;
	bool isOutOfBounds() const;

};
