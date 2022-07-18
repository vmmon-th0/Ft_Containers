#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2>    m;
	CONTAINER::map<TP1,TP2>::key_compare mycomp = m.key_comp();
	for (int i = 0; i < 10; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << mycomp(m.begin()->first, -2)<< std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << mycomp(m.begin()->first, 1)<< std::endl;
    return 0;
}