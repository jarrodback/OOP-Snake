#include "Snake.h"
#include "Constants.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"

RandomNumberGenerator Snake::rng;

Snake::Snake() : MoveableGridItem(SNAKEHEAD, 0, 0)
{
	position_at_random();
	createTail();
	p_mouse = nullptr;
}

bool Snake::has_caught_mouse() const
{
	if (is_at_position(p_mouse->getX(), p_mouse->getY()))
		return true;
	for (Tail body : snakeBody)
		if (body.is_at_position(p_mouse->getX(), p_mouse->getY()))
			return true;
	return false;
}

void Snake::spot_mouse(Mouse* p_mouse)
{
	assert(p_mouse != nullptr);
	this->p_mouse = p_mouse;
}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

	set_direction(snake_dx, snake_dy);

	//Will the snake head hit the body
	bool tailCollision = false;
	for (Tail body : snakeBody)
		if (body.is_at_position(x + snake_dx, y + snake_dy))
			tailCollision = true;

	//If not immbolised and snakehead can move
	if (!immoblised && !tailCollision)
	{
		for (int i = snakeBody.size()-1; i > 0; i--)
		{
			snakeBody.at(i).setPrevX(snakeBody.at(i).getX());
			snakeBody.at(i).setPrevY(snakeBody.at(i).getY());
			snakeBody.at(i).setX(snakeBody.at(i - 1).getX());
			snakeBody.at(i).setY(snakeBody.at(i - 1).getY());
		}
		snakeBody.at(0).setPrevX(snakeBody.at(0).getX());
		snakeBody.at(0).setPrevY(snakeBody.at(0).getY());
		snakeBody.at(0).setX(x);
		snakeBody.at(0).setY(y);
		update_position(snake_dx, snake_dy);
	}
}

void Snake::resetSnake()
{
	//Reset snake to start phase
	immoblised = false;
	snakeBody.clear();
	position_at_random();
	createTail();
}

void Snake::set_direction(int& dx, int& dy) const
{
	assert(p_mouse != nullptr);
	dx = 0; dy = 0;
	if (!immoblised) {
		if (x < p_mouse->getX())
			dx = 1;
		else if (x > p_mouse->getX())
			dx = -1;

		if (y < p_mouse->getY())
			dy = 1;
		else if (y > p_mouse->getY())
			dy = -1;
	}
}
void Snake::createTail()
{
	for (int i = 0; i < 3; i++)
		snakeBody.push_back(Tail(x, y));
}
vector<Tail> Snake::getTail() const
{
	return snakeBody;
}
void Snake::position_at_random()
{
	x = rng.get_random_value(SIZE);
	y = rng.get_random_value(SIZE);
}
void Snake::toggleImmbolise()
{
	immoblised = !immoblised;
}
void Snake::undo()
{
	x = prevX;
	y = prevY;
	for (Tail& body : snakeBody)
		if (body.getPrevX() >= 0 && body.getPrevY() >= 0)
		{
			body.setX(body.getPrevX());
			body.setY(body.getPrevY());
		}
}
ostream& operator<<(ostream& os, Snake& snake)
{
	os << snake.getTail().size() << endl;
	os << snake.getX() << endl;
	os << snake.getY() << endl;
	for (Tail& body : snake.getTail())
	{
		os << body.getX() << endl;
		os << body.getY() << endl;
	}

	return os;
}
