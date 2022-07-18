#include "map_test.hpp"

int
start()
{
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::map<TP1, TP2>	v;
	for (int i = 0; i < 10; ++i)
	{
		v.insert(CONTAINER::make_pair(i, i));
	}
	std::cout << v.begin()->first << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::map<TP1, TP2>::iterator it = v.begin();
	std::cout << it->first << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::map<TP1, TP2>::const_iterator cit = v.begin();
	std::cout << cit->first << std::endl;
	return 0;
}