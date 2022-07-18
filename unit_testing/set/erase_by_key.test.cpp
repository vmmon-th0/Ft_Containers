#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP>    s;
	int i;
	for (int i = 0; i < 10; ++i)
	{
		s.insert(i);
	}
	s.erase(1);
	printContent(s);
	i = s.erase(11);
	std::cout << i << std::endl;
	s.erase(2);
	printContent(s);
	i = s.erase(11);
	printContent(s);
	std::cout << i << std::endl;
	for (int i = 3; i < 10; ++i)
	{
		s.erase(i);
	}
	printContent(s);
	return 0;
}