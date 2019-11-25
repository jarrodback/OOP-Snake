#pragma once
#include "MoveableGridItem.h"
#include <ostream>

class Nut : public MoveableGridItem
{
private:
	bool collected;
public:
	Nut(int x, int y);
	bool has_been_collected() const;
	void respawn();
	void disappear();
	int getX();
	int getY();
};

ostream& operator<<(ostream& os, Nut& nut);
