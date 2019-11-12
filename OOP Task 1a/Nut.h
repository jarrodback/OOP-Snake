#pragma once
#include "Mouse.h"
class Nut
{
private:
	int x, y;
	char symbol;
	bool collected;
	Mouse* mouse1;
public:
	Nut();
	Nut(int x, int y);
	int get_x() const;
	int get_y() const;
	char get_symbol() const;
	bool has_been_collected();
	bool is_at_position(int x, int y);
	void disappear();
	void positionNut();
};

