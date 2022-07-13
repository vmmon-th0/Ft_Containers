#ifndef TEST_STACK_HPP
#define TEST_STACK_HPP

#include "../general.hpp"

#define TP			int
#define FT_STACK	ft::stack<TP>
#define STD_STACK	std::stack<TP>

void	pop_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack);
void	top_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack);
void	size_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack);
void	push_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack);
void	empty_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack);
void	rel_ope_stack_test(FT_STACK& ft_stack, STD_STACK& std_stack);

template<typename T, typename CONTAINER_TYPE>
class MutantStack : public CONTAINER_TYPE
{
	public:

		MutantStack()
		{
		}

		MutantStack(const MutantStack& ref) :
			CONTAINER_TYPE(ref)
		{
		}

		MutantStack(const CONTAINER_TYPE& ref) :
			CONTAINER_TYPE(ref)
		{
		}

		virtual ~MutantStack()
		{
		}
	
		MutantStack&
		operator=(const MutantStack& ref)
		{
			if (this != &ref)
			{
				CONTAINER_TYPE::operator=(ref);
			}
			return *this;
		}

		typedef typename CONTAINER_TYPE::container_type::iterator	iterator;

		iterator
		begin()
		{
			return this->c.begin();
		}

		iterator
		end()
		{
			return this->c.end();
		}
};

#endif