#ifndef TEST_SET_HPP
#define TEST_SET_HPP

#include "../general.hpp"
#include "../../set.hpp"

template<typename ContainerType>
void
fill_random(ContainerType& x)
{
    srand(time(NULL));
    int r = 10000 + (rand() % 10000);
	for (int i = 0; i < r; ++i)
	{
		int k = rand() % 1500;
		x.insert(k);
	}
}

#endif