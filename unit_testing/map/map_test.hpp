#ifndef MAP_TEST
#define MAP_TEST

#include "../general.hpp"

void
printContent(const CONTAINER::map<TP1, TP2>& y)
{
	std::cout << "test [" << x++ << "]" << std::endl;
	for (CONTAINER::map<TP1, TP2>::const_iterator it = y.begin(); it != y.end(); ++it)
	{
		std::cout << "first : " << it->first << std::endl;
		std::cout << "second : " << it->second << std::endl << std::endl; 
	}
	std::cout << y.size() << std::endl;
}

#endif