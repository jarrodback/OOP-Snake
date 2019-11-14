#pragma once

#include "MoveableGridItem.h"
#include "constants.h"
#include "Underground.h"
#include "Nut.h"
class Mouse : public MoveableGridItem{
private:
	// data members
	bool alive;
	bool escaped;
	int mouse_dx;
	int mouse_dy;
public:
	// constructor
	Mouse();
	// accessors
	bool is_alive() const;
	bool has_escaped() const;
	bool has_reached_a_hole(Underground ug) const;
	bool has_reached_nut(Nut nut) const;
	void respawn();
	// mutators
	void die();
	void escape_into_hole();
	void scamper(int key);
};
