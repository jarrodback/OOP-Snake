#include "Player.h"

Player::Player(string name): name(name) 
{
}

string Player::getName() const{
	return name;
}

int Player::getScore() const{
	return score.getAmount();
}

void Player::updateScore(int amount) {
	score.updateAmount(amount);
}

void Player::toggleCheat() {
	cheating = !cheating;
	cheated = true;
}

void Player::resetCheat() {
	cheating = false;
}

bool Player::isCheating() const {
	return cheating;
}

bool Player::hasCheated() const
{
	if (cheated) return true;
	else return false;
}
