#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;
	for (int i = 0; i < 30; ++i)
	{
		v.push_back(i);
	}
	v.erase(v.begin());
	printContent(v);
	v.erase(v.end() - 1);
	printContent(v);
	v.erase(v.begin() + 1);
	printContent(v);
	return 0;
}