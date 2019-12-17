#include "RandomNumberGenerator.h" 
#include <ctime>

RandomNumberGenerator* RandomNumberGenerator::instance = new RandomNumberGenerator();

RandomNumberGenerator::RandomNumberGenerator()
{
	seed();
}

int RandomNumberGenerator::get_random_value(int max) const
{
	// produce a random number in range [1..max]
	return (rand() % max) + 1;
}

RandomNumberGenerator* RandomNumberGenerator::getInstance()
{
	return instance;
}

void RandomNumberGenerator::seed()
{
	// seed the random number generator from current system time
	// so that the numbers will be different every time we run
	srand(static_cast<unsigned>(time(0)));
}