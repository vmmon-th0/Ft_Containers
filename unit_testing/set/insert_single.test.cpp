#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP> s;
	CONTAINER::pair<CONTAINER::set<TP>::iterator, bool> it;
	for (int i = 0; i < 10; ++i)
	{
		s.insert(i);
	}
	it = s.insert(13);
	std::cout << *(it.first) << std::endl;
	std::cout << std::boolalpha << it.second << std::endl;
	printContent(s);
	it = s.insert(14);
	std::cout << *(it.first) << std::endl;
	std::cout << std::boolalpha << it.second << std::endl;
	printContent(s);
	std::cout << "test [" << x++ << "]" << std::endl;
	it = s.insert(9);
	std::cout << *(it.first) << std::endl;
	std::cout << std::boolalpha << it.second << std::endl;
	return 0;
}