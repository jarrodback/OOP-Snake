#pragma once
#include "MoveableGridItem.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Snake {
private:
	static RandomNumberGenerator rng;
	Mouse* p_mouse;
	vector<MoveableGridItem> snakeBody;
	void set_direction(int& dx, int& dy) const;
	void createSnake();
public:
	Snake();
	~Snake();
	vector<MoveableGridItem> getSnake();
	void spot_mouse(Mouse* p_mouse); //sets mouse pointer
	bool has_caught_mouse() const;
	void chase_mouse();
	void resetSnake();
	void position_at_random();
};