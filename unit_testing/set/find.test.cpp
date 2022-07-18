#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP>	s;
	for (int i = 0; i < 10; ++i)
	{
		s.insert(i);
	}
	std::cout << *s.find(1) << std::endl;
	std::cout << *s.find(11) << std::endl;
	std::cout << *s.find(9) << std::endl;
	std::cout << *s.find(5) << std::endl;
	return 0;
}