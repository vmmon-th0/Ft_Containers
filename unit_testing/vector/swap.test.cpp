#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;
	CONTAINER::vector<TP> v2;
	for (int i = 0; i < 1000; ++i)
	{
		v.push_back(i);
	}
	v2.swap(v);
	*v2.begin() *= 2;
	v = v2;
	printContent(v2);
	printContent(v);
	return 0;
}