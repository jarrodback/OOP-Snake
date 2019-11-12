#include "Mouse.h"

Mouse::Mouse() : symbol(MOUSE), x(SIZE / 2), y(SIZE / 2), alive(true), escaped(false), mouse_dx(0), mouse_dy(0) {}

int Mouse::get_x() const { return x; }
int Mouse::get_y() const { return y; }
char Mouse::get_symbol() const { return symbol; }
bool Mouse::is_alive() const { return alive; }
bool Mouse::has_escaped() const { return escaped; }

bool Mouse::is_at_position(int x, int y) const
{
	return this->x == x && this->y == y;
}
bool Mouse::has_reached_a_hole(Underground ug) const
{
	for (int h_no = 0; h_no < (int)ug.getHoles().size(); ++h_no)
	{
		if (is_at_position(ug.getHoles().at(h_no).get_x(), ug.getHoles().at(h_no).get_y()))
		{
			return true;
		}
	}

	return false;
}
bool Mouse::has_reached_nut(Nut nut) const
{
	if(is_at_position(nut.getX(), nut.getY()))
		return true;
}
void Mouse::die()
{
	alive = false;
}
void Mouse::escape_into_hole()
{
	escaped = true;
}

void Mouse::scamper(int key)
{
	switch (key)
	{
	case KEY_LEFT:
		mouse_dx = -1;
		mouse_dy = 0;
		break;
	case KEY_RIGHT:
		mouse_dx = +1;
		mouse_dy = 0;
		break;
	case KEY_UP:
		mouse_dx = 0;
		mouse_dy = -1;
		break;
	case KEY_DOWN:
		mouse_dx = 0;
		mouse_dy = +1;
		break;
	default:
		// not a key we care about, so do nothing
		break;
	}

	// update mouse coordinates if move is possible
	if (((x + mouse_dx) >= 1) && ((x + mouse_dx) <= SIZE) && ((y + mouse_dy) >= 1) && ((y + mouse_dy) <= SIZE))
	{
		update_position(mouse_dx, mouse_dy);
	}
}

void Mouse::update_position(int dx, int dy)
{
	x += dx;
	y += dy;
}