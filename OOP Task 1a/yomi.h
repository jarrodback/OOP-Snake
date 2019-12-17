#pragma once
#include <stdlib.h>	// for srand and rand
#include <cassert>	// for assert
#include <ctime>	   // for time used in seed
class yomi
{
public:
	// constructors

	// accessors
	int get_random_value(int) const;
	static yomi* getInstance();

private:
	yomi();
	// supporting functions#
	void seed();
	static yomi* instance;
};
