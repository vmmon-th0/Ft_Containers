#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP>    s;
	for (int i = 0; i < 10; ++i)
	{
		s.insert(i);
	}
	std::cout << *s.rbegin() << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::set<TP>::reverse_iterator rit = s.rbegin();
	std::cout << *rit << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::set<TP>::const_reverse_iterator crit = s.rbegin();
	std::cout << *crit << std::endl;
	return 0;
}