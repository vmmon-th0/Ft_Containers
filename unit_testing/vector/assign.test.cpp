#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP>	v;
	STD_VECTOR			 	v2;
	STD_SET					s;

	for (int i = 0; i < 1000; ++i)
	{
		v2.push_back(i);
		s.insert(i);
	}
	v.assign(v2.begin(), v2.end());
	printContent(v);
	v.assign(s.begin(), s.end());
	printContent(v);
	v.assign(v2.begin() + 20, v2.end() - 100);
	printContent(v);
	v.reserve(10000);
	v.assign(v2.begin() + 20, v2.end() - 100);
	printContent(v);
	v.resize(10000);
	v.assign(v2.begin() + 20, v2.end() - 100);
	printContent(v);
	v.assign(100, 3);
	printContent(v);
	v.assign(100, 3);
	v.clear();
	v.assign(100, 3);
	printContent(v);
    return 0;
}