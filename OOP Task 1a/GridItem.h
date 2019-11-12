#pragma once
class GridItem
{
protected:
	const char symbol;
	GridItem(char symbol);
public:
	char getSymbol() const;
};

class MoveableGridItem : public GridItem
{
protected:
	int x, y;
	bool is_at_position(int x, int y) const;
	void update_position(int dx, int dy);
public:
	int getX() const;
	int getY() const;
};

class FixedGridItem : public GridItem
{
protected:
	const int x, y;
	bool is_at_position(int x, int y) const;
public:
	int getX() const;
	int getY() const;

};

