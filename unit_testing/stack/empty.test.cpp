#include "stack_test.hpp"

int
start()
{
	CONTAINER::stack<TP> s;
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << s.empty() << std::endl << std::endl;
	s.push(1);
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << s.empty() << std::endl << std::endl;
	s.pop();
	std::cout << "test [" << x++ << "]" << std::endl;
	std::cout << std::boolalpha << s.empty();
	return 0;
}