#pragma once
#include "MoveableGridItem.h"

class Nut : public MoveableGridItem
{
private:
	bool collected;
public:
	Nut(int x, int y);
	bool has_been_collected();
	void respawn();
	void disappear();
};

