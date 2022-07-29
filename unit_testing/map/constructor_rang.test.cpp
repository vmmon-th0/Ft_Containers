#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2> m;
	for (int i = 0; i < 1000; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	CONTAINER::map<TP1, TP2>    m1(m.begin(), m.end());
	printContent(m1);
	return 0;
}