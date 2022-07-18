#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2>    m;
	CONTAINER::map<TP1, TP2>    m2;
	for (int i = 0; i < 10; ++i)
	{
		if (i < 5)
		{
			m.insert(CONTAINER::make_pair(i, i));
		}
		else
		{
			m2.insert(CONTAINER::make_pair(i, i));
		}
	}
	m.swap(m2);
	m.insert(CONTAINER::make_pair(10, 1));
	m2.swap(m);
	printContent(m);
	printContent(m2);
	return 0;
}