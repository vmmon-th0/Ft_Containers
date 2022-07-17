#ifndef STACK_TEST_HPP
#define STACK_TEST_HPP

#include "../general.hpp"

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