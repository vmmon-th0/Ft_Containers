#include "general.hpp"

int
start()
{
    /*-vector-*/
	clock_t c;
    CONTAINER::vector<int>  v(10000, 1);
	c = std::clock();
	for (int i = 0; i < 1000; ++i)
	{
		volatile CONTAINER::vector<int> v(10000, 1);
	}
	for (int i = 0; i < 1000; ++i)
	{
		volatile CONTAINER::vector<int> v2(v.begin(), v.end());
	}
	for (int i = 0; i < 1000; ++i)
	{
		volatile CONTAINER::vector<int> v3(v);
	}
	for (int i = 0; i < 10000; ++i)
	{
		v.push_back(i);
	}
	v.erase(v.begin(), v.end());
	v.insert(v.begin(), 10000, 1);
	for (int i = 0; i < 100; ++i)
	{
		v.pop_back();
	}
	v.clear();
	std::cout << "time elapsed : " << (double)(std::clock() - c) / CLOCKS_PER_SEC << std::endl;
}