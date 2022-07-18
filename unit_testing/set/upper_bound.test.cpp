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
	std::cout << *s.upper_bound(1) << std::endl;
    std::cout << "test [" << x++ << "]" << std::endl;
    std::cout << *s.upper_bound(9) << std::endl;
    std::cout << "test [" << x++ << "]" << std::endl;
    std::cout << *s.upper_bound(5) << std::endl;
    return 0;
}