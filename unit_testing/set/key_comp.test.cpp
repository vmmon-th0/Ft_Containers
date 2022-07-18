#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP>    s;
	CONTAINER::set<TP>::key_compare mycomp = s.key_comp();
	for (int i = 0; i < 10; ++i)
	{
		s.insert(i);
	}
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << mycomp(*s.begin(), -2)<< std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << mycomp(*s.begin(), 1)<< std::endl;
    return 0;
}