#include "yomi.h"

yomi* yomi::instance = new yomi();


yomi::yomi()
{
	seed();
}

int yomi::get_random_value(int max) const
{
	// produce a random number in range [1..max]
	return (rand() % max) + 1;
}

yomi* yomi::getInstance()
{
	return instance;
}

void yomi::seed()
{
	// seed the random number generator from current system time
	// so that the numbers will be different every time we run
	srand(static_cast<unsigned>(time(0)));
}
