#pragma once
#include "MoveableGridItem.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "Tail.h"

class Snake : public MoveableGridItem {
private:
	static RandomNumberGenerator rng;
	Mouse* p_mouse;
	vector<Tail> snakeBody;
	void set_direction(int& dx, int& dy) const;
	void createTail();
	bool immoblised = false;

public:
	Snake();
	void spot_mouse(Mouse* p_mouse); //sets mouse pointer
	bool has_caught_mouse() const;
	void chase_mouse();
	void resetSnake();
	void position_at_random();
	void toggleImmbolise();
	void undo();
	vector<Tail> getTail() const;

};
ostream& operator<<(ostream& os, Snake& snake);
