#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;
    std::cout << "test [" << x++ << "]" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	std::cout << v.front() << std::endl;
    return 0;
}