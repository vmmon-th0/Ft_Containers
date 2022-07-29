#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2>    m;
	for (int i = 0; i < 10; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	std::cout << m.find(1)->first << std::endl;
	std::cout << m.find(11)->first << std::endl;
	std::cout << m.find(9)->first << std::endl;
	std::cout << m.find(5)->first << std::endl;
	return 0;
}