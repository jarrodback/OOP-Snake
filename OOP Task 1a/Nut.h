#pragma once
#include "MoveableGridItem.h"
#include <ostream>

class Nut : public MoveableGridItem
{
private:
	bool collected;
public:
	Nut();
	bool has_been_collected() const;
	void respawn();
	void disappear();
};

ostream& operator<<(ostream& os, Nut& nut);
