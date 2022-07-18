#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP>  s;
	for (int i = 0; i < 10; ++i)
	{
		s.insert(i);
	}
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << s.value_comp()(*s.begin(), *++(s.begin())) << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << s.value_comp()(*++(s.begin()), *s.begin()) << std::endl;
	return 0;
}