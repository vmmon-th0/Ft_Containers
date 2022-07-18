#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2> m;
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << m.empty() << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << m.empty() << std::endl;
	m.clear();
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << m.count(1000) << std::endl;
	printContent(m);
	return 0;
}