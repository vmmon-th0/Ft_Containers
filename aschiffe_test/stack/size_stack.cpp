#include "test_stack.hpp"

void
size_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack)
{
	std::cout << "==============================SIZE==============================" << std::endl
																					<< std::endl;
	ft_stack.size() == std_stack.size() ? 	std::cout << "std::stack and ft::stack have the same size" :
											std::cout << "std::stack and ft::stack do not have the same size";
	std::cout << std::endl << std::endl;
}

int
start()
{
	FT_STACK ft_stack;
	STD_STACK std_stack;
	size_stack_test(ft_stack, std_stack);
	return 0;
}