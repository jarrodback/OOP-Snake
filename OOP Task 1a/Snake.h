#pragma once
#include "MoveableGridItem.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Snake : public MoveableGridItem{
private:
	static RandomNumberGenerator rng;
	Mouse* p_mouse;
	void set_direction(int& dx, int& dy) const;
public:
		Snake();
        ~Snake();
		//Setters
		void spot_mouse(Mouse* p_mouse); //sets mouse pointer
		//Logic
		bool has_caught_mouse() const;
		void chase_mouse();
		void position_at_random();
};