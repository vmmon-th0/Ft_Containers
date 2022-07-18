#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2>    m;
	for (int i = 0; i < 10; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	std::cout << m.rbegin()->first << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::map<TP1, TP2>::reverse_iterator rit = m.rbegin();
	std::cout << rit->first << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::map<TP1, TP2>::const_reverse_iterator crit = m.rbegin();
	std::cout << crit->first << std::endl;
	return 0;
}