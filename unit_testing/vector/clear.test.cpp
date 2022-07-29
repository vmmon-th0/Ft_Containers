#include "vector_test.hpp"

int
start()
{
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::vector<TP> v;
	for (int i = 0; i < 1000; ++i)
	{
		v.push_back(i);
	}
	v.clear();
	std::cout << v.capacity() << std::endl;
	printContent(v);
	return 0;
}