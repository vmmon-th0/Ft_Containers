#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
	}
	v.erase(v.begin(), v.end());
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
	}
	v.erase(v.begin(), v.begin() + 1);
	printContent(v);
	v.erase(v.end() - 2, v.end() - 1);
	printContent(v);
	v.erase(v.begin() + 4, v.end() - 8);
	printContent(v);
	return 0;
}