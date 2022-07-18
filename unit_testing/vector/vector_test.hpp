#ifndef VECTOR_TEST_HPP
#define VECTOR_TEST_HPP

#include "../general.hpp"

void
printContent(const CONTAINER::vector<TP>& y)
{
    std::cout << "test [" << x++ << "]" << std::endl;
	for (CONTAINER::vector<TP>::const_iterator it = y.begin(); it != y.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << y.size() << std::endl;
}

#endif