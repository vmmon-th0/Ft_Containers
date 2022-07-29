#include "set_test.hpp"

int
start()
{
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::set<TP> s;
	typedef CONTAINER::pair<CONTAINER::set<TP1>::iterator,CONTAINER::set<TP>::iterator> 	eq;
	for (int i = 0; i < 10; ++i)
	{
		s.insert(i);
	}
	eq rtvl = s.equal_range(5);
	std::cout << *rtvl.first << std::endl;
	std::cout << *rtvl.second << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	rtvl = s.equal_range(10);
	std::cout << *rtvl.first << std::endl;
	std::cout << *rtvl.second << std::endl;
	return 0;
}