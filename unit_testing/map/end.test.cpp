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
	CONTAINER::map<TP1, TP2>::iterator it = m.end();
	--it;
	std::cout << it->first << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::map<TP1, TP2>::const_iterator cit = m.end();
	--cit;
	std::cout << cit->first << std::endl;
	return 0;
}