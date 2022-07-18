#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2>    m;
	for (int i = 0; i < 10; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
    std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << m.upper_bound(1)->first << std::endl;
    std::cout << "test [" << x++ << "]" << std::endl;
    std::cout << m.upper_bound(9)->first << std::endl;
    std::cout << "test [" << x++ << "]" << std::endl;
    std::cout << m.upper_bound(5)->first << std::endl;
    return 0;
}