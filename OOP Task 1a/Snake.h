#pragma once
#include "MoveableGridItem.h"
#include "Mouse.h"
#include "RandomNumberGenerator.h"
class Snake : public MoveableGridItem{
public:
	struct BodyPart {
	public:
		Snake::BodyPart::BodyPart(int x, int y, char symbol) : x(x), y(y), symbol(symbol)
		{

		}
		Snake::BodyPart::BodyPart() {}
		int x, y;
		char symbol;
	};
private:
	vector<BodyPart> snake;
	BodyPart snakeHead;
	static RandomNumberGenerator rng;
	Mouse* p_mouse;
	void set_direction(int& dx, int& dy) const;
  	void move_tail();
    void createSnake();
public:
		Snake();
        ~Snake();
        	vector<BodyPart> getSnake() const;
		//Setters
		void spot_mouse(Mouse* p_mouse); //sets mouse pointer
		//Logic
		bool has_caught_mouse() const;
		void chase_mouse();
		void position_at_random();
};