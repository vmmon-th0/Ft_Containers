#include "test_stack.hpp"

void
top_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack)
{
	std::cout << "==============================TOP===============================" << std::endl
																					<< std::endl;
	std::cout << CCYAN("Push a value -> ") << std::endl;
	ft_stack.push(1);
	std_stack.push(1);
	std::cout 	<< "std::stack top() rtvl : " << std_stack.top() << std::endl;
	std::cout 	<< "ft::stack top() rtvl : " << ft_stack.top() << std::endl << std::endl;
	std::cout << CCYAN("Push another value -> ") << std::endl;
	ft_stack.push(2);
	std_stack.push(2);
	std::cout 	<< "std::stack top() rtvl : " << std_stack.top() << std::endl;
	std::cout 	<< "ft::stack top() rtvl : " << ft_stack.top() << std::endl << std::endl;
	std::cout << CCYAN("Pop() -> ") << std::endl;
	ft_stack.pop();
	std_stack.pop();
	std::cout 	<< "std::stack top() rtvl : " << std_stack.top() << std::endl;
	std::cout 	<< "ft::stack top() rtvl : " << ft_stack.top() << std::endl << std::endl;
	ft_stack.pop();
	std_stack.pop();
}

int
start()
{
	FT_STACK ft_stack;
	STD_STACK std_stack;
	top_stack_test(ft_stack, std_stack);
	return 0;
}