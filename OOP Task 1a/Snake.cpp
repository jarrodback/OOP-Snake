#include "Snake.h"
#include "Constants.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"

RandomNumberGenerator Snake::rng;

Snake::Snake() : MoveableGridItem(SNAKEHEAD)
//calls default
{
	//symbol = SNAKEHEAD;
	position_at_random();
	// make the pointer safe before the snake spots the mouse
	p_mouse = nullptr;
}
Snake::~Snake()
{

}
bool Snake::has_caught_mouse() const
{
	return is_at_position(p_mouse->getX(), p_mouse->getY());
}

void Snake::spot_mouse(Mouse* p_mouse)
{
	// pre-condition: the mouse needs to exist 
	assert(p_mouse != nullptr);

	this->p_mouse = p_mouse;
}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

	//identify direction of travel
	set_direction(snake_dx, snake_dy);

	//go in that direction
	//update_position(snake_dx, snake_dy);
}

void Snake::set_direction(int& dx, int& dy) const
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse != nullptr);

	// assume snake only moves when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (x < p_mouse->getX())         // if snake on left of mouse
		dx = 1;                        // snake should move right
	else if (x > p_mouse->getX())    // if snake on left of mouse
		dx = -1;						       // snake should move left

	if (y < p_mouse->getY())         // if snake is above mouse
		dy = 1;                        // snake should move down
	else if (y > p_mouse->getY())    // if snake is below mouse
		dy = -1;						       // snake should move up
}
void Snake::position_at_random()
{
	// WARNING: this may place on top of other things
	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
}