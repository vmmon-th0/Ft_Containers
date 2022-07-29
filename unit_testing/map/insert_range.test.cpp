#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2> m;
	CONTAINER::map<TP1, TP2> m1;
	CONTAINER::map<TP1, TP2> m2;
	CONTAINER::map<TP1, TP2> m3;
	for (int i = 0; i < 30; ++i)
	{
		if (i < 10)
		{
			m1.insert(CONTAINER::make_pair(i, i));
		}
		else if (i >= 10 && i < 20)
		{
			m2.insert(CONTAINER::make_pair(i, i));
		}
		else
		{
			m3.insert(CONTAINER::make_pair(i, i));
		}
	}
	m.insert(m1.begin(), m1.end());
	printContent(m);
	m.insert(m2.begin(), m2.end());
	printContent(m);
	m.insert(m2.begin(), m2.begin());
	printContent(m);
	m.insert(m3.begin(), m3.end());
	printContent(m);
	m.insert(m3.begin(), m3.begin());
	printContent(m);
	return 0;
}