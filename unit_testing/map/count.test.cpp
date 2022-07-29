#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2> m;
	for (int i = 0; i < 1000; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << m.count(1) << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << m.count(1000) << std::endl;
	return 0;
}