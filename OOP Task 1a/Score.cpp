#include "Score.h"

Score::Score() : amount(0)
{}

int Score::getAmount() const{
	return amount;
}

void Score::updateAmount(int amount) {
	this->amount = amount;
}
