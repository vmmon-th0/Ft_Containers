#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP>	v;
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
	}
	std::cout << v.at(0) << std::endl;
	std::cout << v.at(50) << std::endl;
	std::cout << v.at(99) << std::endl;
	return 0;
}