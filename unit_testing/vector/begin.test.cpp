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
	std::cout << *v.begin() << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::vector<TP>::iterator it = v.begin();
	std::cout << *it << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::vector<TP>::const_iterator cit = v.begin();
	std::cout << *cit << std::endl;
	return 0;
}