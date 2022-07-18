#include "set_test.hpp"

int
start()
{
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::set<TP>	set;
	for (int i = 0; i < 10; ++i)
	{
		set.insert(i);
	}
	std::cout << *set.begin() << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::set<TP>::iterator it = set.begin();
	std::cout << *it << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::set<TP>::const_iterator cit = set.begin();
	std::cout << *cit << std::endl;
	return 0;
}