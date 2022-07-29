#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;
	for (int i = 0; i < 1000; ++i)
	{
		v.push_back(i);
	}
	CONTAINER::vector<TP> v1;
	v1 = v;
	printContent(v1);
	for (CONTAINER::vector<TP>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		*it *= 2;
	}
	v = v1;
	printContent(v);
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::vector<CONTAINER::vector<TP> > v2(3, CONTAINER::vector<TP>(10, 1));
	CONTAINER::vector<CONTAINER::vector<TP> > v3;
	v3 = v2;
	for (CONTAINER::vector<CONTAINER::vector<TP> >::iterator it = v3.begin(); it != v3.end(); ++it)
	{
		for (CONTAINER::vector<TP>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
		{
			std::cout << *it2 << std::endl;
		}
	}
	return 0;
}