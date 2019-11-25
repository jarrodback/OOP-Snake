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
	int GetX();
	int GetY();
};

ostream& operator<<(ostream& os, const Nut& nut);
