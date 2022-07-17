#include "stack_test.hpp"

int
start()
{
	CONTAINER::stack<TP> s;
	MutantStack<TP, CONTAINER::stack<TP> > ms(s);
	std::cout << "test [" << x++ << "]" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		ms.push(i);
	}
	for (MutantStack<TP, CONTAINER::stack<TP> >::iterator it = ms.begin(); it != ms.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}