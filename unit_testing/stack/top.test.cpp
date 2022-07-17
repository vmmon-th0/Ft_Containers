#include "stack_test.hpp"

int
start()
{
	CONTAINER::stack<TP> s;
	std::cout << "test [" << x++ << "]" << std::endl;
	s.push(1);
	s.push(2);
	std::cout << s.top() << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	return 0;
}