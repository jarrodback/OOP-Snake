#pragma once
class Nut
{
private:
	int x, y;
	char symbol;
	bool collected;
public:
	Nut();
	Nut(int x, int y);
	int getX() const;
	int getY() const;
	char get_symbol() const;
	bool has_been_collected();
	bool is_at_position(int x, int y);
	void positionNut();
	void disappear();
};

