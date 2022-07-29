#include "map_test.hpp"

int
start()
{
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::map<TP1, TP2> m;
	typedef CONTAINER::pair<CONTAINER::map<TP1,TP2>::iterator,CONTAINER::map<TP1,TP2>::iterator> 	eq;
	for (int i = 0; i < 10; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	eq rtvl = m.equal_range(5);
	std::cout << rtvl.first->first << std::endl;
	std::cout << rtvl.second->second << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	rtvl = m.equal_range(10);
	std::cout << rtvl.first->first << std::endl;
	std::cout << rtvl.second->second << std::endl;
	return 0;
}