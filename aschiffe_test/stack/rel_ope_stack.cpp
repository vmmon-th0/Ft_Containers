#include "test_stack.hpp"

void
rel_ope_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack)
{
	FT_STACK	ft_stack_s;
	STD_STACK	std_stack_s;

	std::cout << "==============================REL_OPE===========================" << std::endl
																					<< std::endl;
	ft_stack.push(10);
	ft_stack_s.push(5);
	
	std_stack.push(10);
	std_stack_s.push(5);

	(ft_stack > ft_stack_s) == (std_stack > std_stack_s) ?		std::cout << CGREEN(">  Relationnal operator success") :
																std::cout << CRED("> Relationnal operator fails"); std::cout << std::endl;
	(ft_stack < ft_stack_s) == (std_stack < std_stack_s) ?		std::cout << CGREEN("<  Relationnal operator success") :
																std::cout << CRED("< Relationnal operator fails"); std::cout << std::endl;
	(ft_stack == ft_stack_s) == (std_stack == std_stack_s) ?	std::cout << CGREEN("== Relationnal operator success") :
																std::cout << CRED("== Relationnal operator fails"); std::cout << std::endl;
	(ft_stack != ft_stack_s) == (std_stack != std_stack_s) ? 	std::cout << CGREEN("!= Relationnal operator success") :
																std::cout << CRED("!= Relationnal operator fails"); std::cout << std::endl;
	(ft_stack <= ft_stack_s) == (std_stack <= std_stack_s) ? 	std::cout << CGREEN("<= Relationnal operator success") :
																std::cout << CRED("<= Relationnal operator fails"); std::cout << std::endl;
	(ft_stack >= ft_stack_s) == (std_stack >= std_stack_s) ? 	std::cout << CGREEN(">= Relationnal operator success") :
																std::cout << CRED(">= Relationnal operator fails"); std::cout << std::endl;
	std::cout << std::endl;
}

int
start()
{
	FT_STACK ft_stack;
	STD_STACK std_stack;
	rel_ope_stack_test(ft_stack, std_stack);
	return 0;
}