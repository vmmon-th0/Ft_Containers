#include "test_stack.hpp"

void
print_state(FT_STACK& ft_stack, STD_STACK& std_stack)
{
	MutantStack<TP, FT_STACK> ft_mutant_stack(ft_stack);
	MutantStack<TP, STD_STACK> std_mutant_stack(std_stack);
	std::cout << "ft::stack content : ";
	for (MutantStack<TP, FT_STACK>::iterator it = ft_mutant_stack.begin(); it != ft_mutant_stack.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != ft_mutant_stack.end())
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl <<  "std::stack content : ";
	for (MutantStack<TP, STD_STACK>::iterator it = std_mutant_stack.begin(); it != std_mutant_stack.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != std_mutant_stack.end())
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl << std::endl;
}

void
pop_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack)
{
	std::cout << "==============================POP===============================" << std::endl
																					<< std::endl;
	std::cout << CCYAN("Add 10 values in the stack -> ") << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		ft_stack.push(i);
		std_stack.push(i);
	}
	std::cout << "current state" << std::endl;
	print_state(ft_stack, std_stack);
	std::cout << "pop() 3 elements" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		ft_stack.pop();
		std_stack.pop();
	}
	print_state(ft_stack, std_stack);
	std::cout << "pop() 7 elements" << std::endl;
	for (int i = 0; i < 7; ++i)
	{
		ft_stack.pop();
		std_stack.pop();
	}
	print_state(ft_stack, std_stack);
}

int
start()
{
	FT_STACK ft_stack;
	STD_STACK std_stack;
	pop_stack_test(ft_stack, std_stack);
	return 0;
}