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
vector<MoveableGridItem> Snake::getSnake() const
{
	return snakeBody;
}
bool Snake::has_caught_mouse() const
{
	for (MoveableGridItem snakePart : snakeBody)
		if (snakePart.is_at_position(p_mouse->getX(), p_mouse->getY()))
			return true;
	return false;
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
	bool collision = false;
	for (MoveableGridItem body : snakeBody)
	{
		if (body.is_at_position(snakeBody.at(0).getX() + snake_dx, snakeBody.at(0).getY() + snake_dy))
		{
			collision = true;
		}
	}
	if (!immoblised && collision == false) {
		for (int x = snakeBody.size() - 1; x > 0; x--)
		{
			snakeBody.at(x).SetX(snakeBody.at(x - 1).getX());
			snakeBody.at(x).SetY(snakeBody.at(x - 1).getY());
		}
		snakeBody.at(0).update_position(snake_dx, snake_dy);
	}
}

void Snake::resetSnake() {
	immoblised = false;
	snakeBody.clear();
	createSnake();
}

void Snake::set_direction(int& dx, int& dy) const
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse != nullptr);

	// assume snake only moves when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (!immoblised) {
		if (snakeBody.at(0).getX() < p_mouse->getX())         // if snake on left of mouse
			dx = 1;                        // snake should move right
		else if (snakeBody.at(0).getX() > p_mouse->getX())    // if snake on left of mouse
			dx = -1;						       // snake should move left

		if (snakeBody.at(0).getY() < p_mouse->getY())         // if snake is above mouse
			dy = 1;                        // snake should move down
		else if (snakeBody.at(0).getY() > p_mouse->getY())    // if snake is below mouse
			dy = -1;						       // snake should move up
	}
}
void Snake::createSnake()
{
	snakeBody.push_back(MoveableGridItem(SNAKEHEAD));
	for (int x = 0; x < 3; x++)
	{
		snakeBody.push_back(MoveableGridItem(SNAKETAIL));
	}
}
void Snake::position_at_random()
{
	// WARNING: this may place on top of other things
	int x = rng.get_random_value(SIZE);
	int y = rng.get_random_value(SIZE);
	snakeBody.at(0).SetX(x);
	snakeBody.at(0).SetY(y);
}
void Snake::toggleImmbolise() {
	immoblised = !immoblised;
}
ostream& operator<<(ostream& os, const Snake& snake)
{
	os << snake.getSnake().size() << endl;
	for (MoveableGridItem body : snake.getSnake())
	{
		os << body.getX() << endl;
		os << body.getY() << endl;
	}

	return os;
}
