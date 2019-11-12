#pragma once
#include "GridItem.h"
class MoveableGridItem : public GridItem
{
protected:
	int x, y;
public:
	MoveableGridItem(char symbol);
	void update_position(int dx, int dy);
	bool is_at_position(int x, int y) const;
	void SetX(int dx);
	void SetY(int dy);
	int getX() const;
	int getY() const;
};
