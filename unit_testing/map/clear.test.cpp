#include "map_test.hpp"

int
start()
{
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::map<TP1, TP2> v;
	for (int i = 0; i < 1000; ++i)
	{
		v.insert(CONTAINER::make_pair(i, i));
	}
	v.clear();
	printContent(v);
	return 0;
}