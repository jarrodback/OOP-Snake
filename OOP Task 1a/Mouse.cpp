#include "Mouse.h"

Mouse::Mouse() : MoveableGridItem(MOUSE), alive(true), escaped(false), mouse_dx(0), mouse_dy(0)
{
	x = (SIZE / 2);
	y = (SIZE / 2);
}

int Mouse::getDirectionX() const { return mouse_dx; }
int Mouse::getDirectionY() const { return mouse_dy; }
bool Mouse::is_alive() const { return alive; }
bool Mouse::has_escaped() const { return escaped; }
bool Mouse::has_reached_a_hole(Underground ug) const { return ug.is_hole_at_position(x, y); }
bool Mouse::has_reached_nut(Nut nut) const { return is_at_position(nut.getX(), nut.getY()); }
void Mouse::escape_into_hole() { escaped = true; }
void Mouse::die() { alive = false; }
void Mouse::teleport(Underground ug) { ug.moveToAnotherHole(x, y); }


void Mouse::respawn() {
	alive = true;
	escaped = false;
	x = (SIZE / 2);
	y = (SIZE / 2);
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
		update_position(mouse_dx, mouse_dy);
}

ostream& operator<<(ostream& os, const Mouse& mouse)
{
	if (mouse.is_alive())
	{
		os << "mouse_alive" << endl;
		os << mouse.getX() << endl;
		os << mouse.getY() << endl;
	}
	else
		os << "mouse_dead" << endl;
	return os;
}
//nice