#pragma once

#include "MoveableGridItem.h"
#include "constants.h"
#include "Underground.h"
#include "Nut.h"
class Mouse : public MoveableGridItem{
private:
	bool alive;
	bool escaped;
	int mouse_dx;
	int mouse_dy;
public:
	Mouse();
	int getDirectionX() const;
	int getDirectionY() const;
	
	bool is_alive() const;
	bool has_escaped() const;
	bool has_reached_a_hole(Underground ug) const;
	bool has_reached_nut(Nut nut) const;
	
	void respawn();
	void die();
	void escape_into_hole();
	void scamper(int key);
	void teleport(Underground ug);
};
ostream& operator<<(ostream& os, const Mouse& mouse);