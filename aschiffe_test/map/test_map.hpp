#ifndef TEST_MAP
#define TEST_MAP

#include <vector>
#include <numeric>
#include <iostream>
#include <list>
#include "../general.hpp"
#include "../../map.hpp"

#ifndef NB_SAMPLES
#define NB_SAMPLES 100
#endif

template<typename ContainerType>
void
ft_fill_random(ContainerType& x)
{
	srand(time(NULL));
	int r = 10000 + (rand() % 10000);
	for (int i = 0; i < r; ++i)
	{
		int f = rand() % 1500;
		int s = rand() % 500;
		x.insert(ft::make_pair(f, s));
	}
}

template<typename ContainerType>
void
std_fill_random(ContainerType& x)
{
	srand(time(NULL));
	int r = 10000 + (rand() % 10000);
	for (int i = 0; i < r; ++i)
	{
		int f = rand() % 1500;
		int s = rand() % 500;
		x.insert(std::make_pair(f, s));
	}
}

#endif