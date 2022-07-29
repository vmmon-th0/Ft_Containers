#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP> s;
	for (int i = 0; i < 1000; ++i)
	{
		s.insert(i);
	}
	CONTAINER::set<TP> s1(s);
	printContent(s1);
	return 0;
}