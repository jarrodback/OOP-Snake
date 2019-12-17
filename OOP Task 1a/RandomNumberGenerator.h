#pragma once

#include <stdlib.h>	// for srand and rand
#include <cassert>	// for assert
#include <ctime>	   // for time used in seed

using namespace std;

class RandomNumberGenerator
{
	public:
		int get_random_value(int) const;
		static RandomNumberGenerator* getInstance();
	private:
		void seed();
		RandomNumberGenerator();
		static RandomNumberGenerator* instance;
};