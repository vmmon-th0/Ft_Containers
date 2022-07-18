#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
	}
    v.pop_back();
    printContent(v);
    for (int i = 0; i < 10; ++i)
    {
        v.pop_back();
    }
	printContent(v);
	return 0;
}