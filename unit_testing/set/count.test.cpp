#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP> s;
	for (int i = 0; i < 1000; ++i)
	{
		s.insert(i);
	}
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << s.count(1) << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << s.count(1000) << std::endl;
	return 0;
}