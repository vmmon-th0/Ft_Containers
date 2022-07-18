#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v(1);
	for (int i = 0; i < 100; ++i)
	{
		v.insert(v.begin(), i);
	}
	v.resize(50);
	printContent(v);
	v.resize(150);
	printContent(v);
	v.resize(200);
	printContent(v);
	v.resize(0);
	printContent(v);
	return 0;
}