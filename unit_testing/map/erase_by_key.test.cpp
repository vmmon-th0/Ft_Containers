#include "map_test.hpp"

int
start()
{
	int i = 0;
	CONTAINER::map<TP1, TP2>    m;
	for (int i = 0; i < 10; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	i = m.erase(1);
	printContent(m);
	std::cout << i << std::endl;
	m.erase(2);
	i = m.erase(11);
	printContent(m);
	std::cout << i << std::endl;
	m.erase(11);
	printContent(m);
	for (int i = 3; i < 10; ++i)
	{
		m.erase(i);
	}
	printContent(m);
	return 0;
}