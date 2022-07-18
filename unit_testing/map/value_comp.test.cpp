#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2>    m;
	for (int i = 0; i < 10; ++i)
	{
		m.insert(CONTAINER::make_pair(i, i));
	}
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << m.value_comp()(*m.begin(), *++(m.begin())) << std::endl;
    std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << m.value_comp()(*++(m.begin()), *m.begin()) << std::endl;
    return 0;
}