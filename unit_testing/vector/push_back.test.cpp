#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
	}
	printContent(v);
	return 0;
}