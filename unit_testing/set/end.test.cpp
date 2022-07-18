#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP>    s;
	for (int i = 0; i < 10; ++i)
	{
		s.insert(i);
	}
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::set<TP>::iterator it = s.end();
	--it;
	std::cout << *it << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::set<TP>::const_iterator cit = s.end();
	--cit;
	std::cout << *cit << std::endl;
	return 0;
}