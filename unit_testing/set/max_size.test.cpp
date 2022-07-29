#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP>    s;
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << s.max_size() << std::endl;
	return 0;
}