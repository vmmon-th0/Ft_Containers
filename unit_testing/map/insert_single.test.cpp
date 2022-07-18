#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2> m;
	CONTAINER::pair<CONTAINER::map<TP1, TP2>::iterator, bool> it;
	for (int i = 0; i < 10; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	it = m.insert(CONTAINER::make_pair(13, 1));
	std::cout << it.first->first << std::endl;
	std::cout << std::boolalpha << it.second << std::endl;
	printContent(m);
	it = m.insert(CONTAINER::make_pair(14, 1));
	std::cout << it.first->first << std::endl;
	std::cout << std::boolalpha << it.second << std::endl;
	printContent(m);
	std::cout << "test [" << x++ << "]" << std::endl;
	it = m.insert(CONTAINER::make_pair(9, 1));
	std::cout << it.first->first << std::endl;
	std::cout << std::boolalpha << it.second << std::endl;
	return 0;
}