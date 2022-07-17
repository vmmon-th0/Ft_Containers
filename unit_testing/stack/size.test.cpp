#include "stack_test.hpp"

int
start()
{
	CONTAINER::stack<TP> s;

	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << s.size() << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		s.push(i);
	}
	std::cout << s.size() << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		s.pop();
	}
	std::cout << s.size() << std::endl;
	return 0;
}