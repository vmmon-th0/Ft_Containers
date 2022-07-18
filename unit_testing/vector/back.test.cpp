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
	std::cout << v.back() << std::endl;
    std::cout << "test [" << x++ << "]" << std::endl;
    v.pop_back();
    std::cout << v.back() << std::endl;
    return 0;
}