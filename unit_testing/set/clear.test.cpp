#include "set_test.hpp"

int
start()
{
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::set<TP> s;
	for (int i = 0; i < 1000; ++i)
	{
		s.insert(i);
	}
	s.clear();
	printContent(s);
	return 0;
}