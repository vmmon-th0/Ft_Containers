#include "vector_test.hpp"

int
start()
{
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::vector<TP>	v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	std::cout << *(v.end() - 1) << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::vector<TP>::iterator it = v.end();
	std::cout << *(it - 1) << std::endl;
	CONTAINER::vector<TP>::const_iterator cit = v.end();
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << *(cit - 1) << std::endl;
	return 0;
}