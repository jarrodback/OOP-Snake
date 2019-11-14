#pragma once
#include "FixedGridItem.h"

class Nut : public FixedGridItem
{
private:
	bool collected;
public:
	Nut(int x, int y);
	bool has_been_collected();
	void disappear();
	void respawn();
};

