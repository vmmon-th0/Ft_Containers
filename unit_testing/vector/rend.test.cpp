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
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::vector<TP>::reverse_iterator rit= v.rend();
	--rit;
	std::cout << *rit << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	--rit;
	CONTAINER::vector<TP>::const_reverse_iterator rit2 = v.rend();
	std::cout << *rit2 << std::endl;
	return 0;
}