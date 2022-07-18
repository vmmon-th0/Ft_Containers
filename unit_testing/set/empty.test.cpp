#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP> s;
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << s.empty() << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		s.insert(i);
	}
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << s.empty() << std::endl;
	s.clear();
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << s.count(1000) << std::endl;
	printContent(s);
	return 0;
}