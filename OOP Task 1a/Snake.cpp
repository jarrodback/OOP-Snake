#include "Snake.h"
#include "Constants.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"
RandomNumberGenerator Snake::rng;

Snake::Snake()
//calls default
{
	createSnake();
	position_at_random();

	// make the pointer safe before the snake spots the mouse
	p_mouse = nullptr;
}

Snake::~Snake()
{

}
int Snake::getX() const { return snakeHead.x; }
int Snake::getY() const { return snakeHead.y; }
char Snake::getSymbol() const { return snakeHead.symbol; }

bool Snake::is_at_position(int x, int y) const
{
	return (this->snakeHead.x == x) && (this->snakeHead.y == y);
}

bool Snake::has_caught_mouse() const
{
	for (BodyPart bp : snake)
	{
		if (p_mouse->get_x() == bp.x && p_mouse->get_y() == bp.y)
		{
			return true;
		}
	}
	return false;
	//return is_at_position(p_mouse->get_x(), p_mouse->get_y());
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
	update_position(snake_dx, snake_dy);
}

void Snake::createSnake()
{
	snake.push_back(BodyPart{ 0, 0, SNAKEHEAD });
	snakeHead = snake[0];
	for (int x = 0; x < 3; x++)
		snake.push_back(BodyPart(getX(), getY(), SNAKETAIL));
}
void Snake::set_direction(int& dx, int& dy) const
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse != nullptr);

	// assume snake only moves when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (snakeHead.x < p_mouse->get_x())         // if snake on left of mouse
		dx = 1;                        // snake should move right
	else if (snakeHead.x > p_mouse->get_x())    // if snake on left of mouse
		dx = -1;						       // snake should move left

	if (snakeHead.y < p_mouse->get_y())         // if snake is above mouse
		dy = 1;                        // snake should move down
	else if (snakeHead.y > p_mouse->get_y())    // if snake is below mouse
		dy = -1;						       // snake should move up
}

void Snake::update_position(int dx, int dy)
{
	snakeHead.x += dx;
	snakeHead.y += dy;
	snake[0] = snakeHead;
	move_tail();
}
void Snake::move_tail()
{
	for (int t = snake.size() - 1; t > 0; t--)
	{
		snake[t].x = snake[t - 1].x;
		snake[t].y = snake[t - 1].y;
	}
}
void Snake::position_at_random()
{
	// WARNING: this may place on top of other things
	snakeHead.x = rng.get_random_value(SIZE);
	snakeHead.y = rng.get_random_value(SIZE);
}


