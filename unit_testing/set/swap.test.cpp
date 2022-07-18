#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP>    s;
	CONTAINER::set<TP>    s2;
	for (int i = 0; i < 10; ++i)
	{
		if (i < 5)
		{
			s.insert(i);
		}
		else
		{
			s2.insert(i);
		}
	}
	s.swap(s2);
	s.insert(10);
	s2.swap(s);
	printContent(s);
	printContent(s2);
	return 0;
}