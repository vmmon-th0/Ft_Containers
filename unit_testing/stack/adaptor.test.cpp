#include "stack_test.hpp"

int
start()
{
	std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::stack<TP, std::deque<TP> > s;
	return 0;
}