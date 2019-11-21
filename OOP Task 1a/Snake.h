#pragma once
#include "MoveableGridItem.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"
//todo bring head out of vector and inherit
class Snake {
private:
	static RandomNumberGenerator rng;
	Mouse* p_mouse;
	vector<MoveableGridItem> snakeBody;
	void set_direction(int& dx, int& dy) const;
	void createSnake();
	bool immoblised = false;
public:
	Snake();
	~Snake();
	vector<MoveableGridItem>& getSnake();
	void spot_mouse(Mouse* p_mouse); //sets mouse pointer
	bool has_caught_mouse() const;
	void chase_mouse();
	void resetSnake();
	void position_at_random();
	void toggleImmbolise();
};