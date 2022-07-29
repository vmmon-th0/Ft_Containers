#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2>    m;
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << m.max_size() << std::endl;
	return 0;
}