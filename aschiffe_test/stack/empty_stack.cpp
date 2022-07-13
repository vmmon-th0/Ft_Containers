#include "test_stack.hpp"

void
printEmpty(FT_STACK& ft_stack, STD_STACK& std_stack)
{
	std::cout	<< "std::stack is empty : "
				<<  (std_stack.empty() ? CGREEN("true") : CRED("false"))
				<< std::endl;

	std::cout 	<< "ft::stack is empty : "
				<<  (ft_stack.empty() ? CGREEN("true") : CRED("false"))
				<< std::endl << std::endl;	
}

void
empty_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack)
{
	std::cout << "==============================EMPTY=============================" << std::endl
																					<< std::endl;
	std::cout << CCYAN("testing empty stack -> ") << std::endl;
	printEmpty(ft_stack, std_stack);
	std::cout << CCYAN("push a value in both stack -> ") << std::endl;
	ft_stack.push(2);
	std_stack.push(2);
	printEmpty(ft_stack, std_stack);
	std::cout << CCYAN("pop a value in both stack -> ") << std::endl;
	ft_stack.pop();
	std_stack.pop();
	printEmpty(ft_stack, std_stack);
}

int
start()
{
	FT_STACK ft_stack;
	STD_STACK std_stack;
	empty_stack_test(ft_stack, std_stack);
	return 0;
}