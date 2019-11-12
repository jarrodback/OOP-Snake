#pragma once
#include "GridItem.h"
class MoveableGridItem : public GridItem
{
protected:
	int x, y;
	MoveableGridItem(char symbol);
	bool is_at_position(int x, int y) const;
	void update_position(int dx, int dy);
public:
	int getX() const;
	int getY() const;
};
