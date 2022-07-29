#ifndef SET_TEST_HPP
#define SET_TEST_HPP

#include "../general.hpp"

void
printContent(const CONTAINER::set<TP>& y)
{
	std::cout << "test [" << x++ << "]" << std::endl;
	for (CONTAINER::set<TP>::const_iterator it = y.begin(); it != y.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << y.size() << std::endl;
}

#endif