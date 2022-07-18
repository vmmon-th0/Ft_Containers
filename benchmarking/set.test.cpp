#include "general.hpp"

int
start()
{
	/*-set-*/
	clock_t c;
	CONTAINER::set<int>	se;
	for (int i = 0; i < 10000; ++i)
	{
		se.insert(i);
	}
	c = std::clock();
	for (int i = 0; i < 100; i++)
	{
		volatile CONTAINER::set<int> v(se.begin(), se.end());
	}
	for (int i = 0; i < 100; i++)
	{
		volatile CONTAINER::set<int> y(se);
	}
	se.find(500);
	se.erase(se.begin(), se.end());
	for (int i = 0; i < 100000; ++i)
	{
		se.insert(i);
	}
	std::cout << "time elapsed : " << (double)(std::clock() - c) / CLOCKS_PER_SEC << "[s]" << std::endl;
}