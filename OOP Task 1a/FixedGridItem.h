#pragma once
#include "GridItem.h"
class FixedGridItem : public GridItem
{
protected:
	const int x, y;
	FixedGridItem(char symbol, int x, int y);
	FixedGridItem(char symbol);
public:
	int getX() const;
	int getY() const;
	bool is_at_position(int x, int y) const;
};


