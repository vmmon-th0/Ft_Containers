#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP> s;

	STD_VECTOR v1;
	STD_VECTOR v2;
	STD_VECTOR v3;
	for (int i = 0; i < 30; ++i)
	{
		if (i < 10)
		{
			v1.push_back(i);
		}
		else if (i >= 10 && i < 20)
		{
			v2.push_back(i);
		}
		else
		{
			v3.push_back(i);
		}
	}
	s.insert(v1.begin(), v1.end());
	printContent(s);
	s.insert(v2.begin(), v2.end() - 7);
	printContent(s);
	s.insert(v2.begin() + 1, v2.begin() + 2);
	printContent(s);
	s.insert(v3.begin(), v3.end());
	printContent(s);
	s.insert(v3.begin(), v3.begin() + 1);
	printContent(s);
	return 0;
}