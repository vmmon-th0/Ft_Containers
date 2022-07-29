#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << v.empty() << std::endl;
	CONTAINER::vector<TP> v2(1, 1);
	std::cout << std::boolalpha << v2.empty() << std::endl;
	return 0;
}