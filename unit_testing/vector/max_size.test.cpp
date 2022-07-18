#include "vector_test.hpp"

int
start()
{
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::vector<TP> v;
	std::cout << v.max_size() << std::endl;
	return 0;
}