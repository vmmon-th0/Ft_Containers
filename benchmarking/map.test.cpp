#include "general.hpp"

int
start()
{
	/*-map-*/
	clock_t c;
	CONTAINER::map<int, int>	m;
	for (int i = 0; i < 10000; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	c = std::clock();
	for (int i = 0; i < 100; i++)
	{
		volatile CONTAINER::map<int, int> v(m.begin(), m.end());
	}
	for (int i = 0; i < 100; i++)
	{
		volatile CONTAINER::map<int, int> y(m);
	}
	m.find(500);
	m.erase(m.begin(), m.end());
	for (int i = 0; i < 100000; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	std::cout << "time elapsed : " << (double)(std::clock() - c) / CLOCKS_PER_SEC << std::endl;
}