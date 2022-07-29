#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;
	std::cout << "test [" << x++ << "]" << std::endl;
	v.reserve(1);
	std::cout << std::boolalpha << v.capacity() << std::endl;
	v.reserve(2000);
	std::cout << std::boolalpha << v.capacity() << std::endl;
	CONTAINER::vector<TP> v2(10, 1);
	v2.reserve(100);
	std::cout << std::boolalpha << v.capacity() << std::endl;
	printContent(v2);
	v2.reserve(1);
	printContent(v2);
	return 0;
}