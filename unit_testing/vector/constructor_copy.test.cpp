#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;
	for (int i = 0; i < 1000; ++i)
	{
		v.push_back(i);
	}
	CONTAINER::vector<TP> v1(v);
	printContent(v1);
	return 0;
}