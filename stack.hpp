#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include <iostream>
#include "vector.hpp"
#include "rainbow.hpp"

namespace ft
{
	template<typename Tp, typename Sequence = ft::vector<Tp> >
	class stack
	{

		public :

			typedef typename	Sequence::size_type 		size_type;
			typedef typename	Sequence::value_type 		value_type;
			typedef typename	Sequence::reference 		reference;
			typedef typename	Sequence::const_reference 	const_reference;
			typedef				Sequence					container_type;

			/* We  declare these operator overload prototypes inside the class because they use a protected attribute inside their function.
			A friend function is a function that is not a member of a class but has access to the class's private and protected members. */

			template<typename Tp1, typename Sequence1>
				friend bool operator==(const stack<Tp1, Sequence1>& x,
										const stack<Tp1, Sequence1>& y);

			template<typename Tp1, typename Sequence1>
				friend bool operator<(const stack<Tp1, Sequence1>& x,
										const stack<Tp1, Sequence1>& y);

			template<typename Tp1, typename Sequence1>
				friend bool operator!=(const stack<Tp1, Sequence1>& x,
										const stack<Tp1, Sequence1>& y);

			template<typename Tp1, typename Sequence1>
				friend bool operator>(const stack<Tp1, Sequence1>& x,
										const stack<Tp1, Sequence1>& y);

			template<typename Tp1, typename Sequence1>
				friend bool operator>=(const stack<Tp1, Sequence1>& x,
										const stack<Tp1, Sequence1>& y);

			template<typename Tp1, typename Sequence1>
				friend bool operator<=(const stack<Tp1, Sequence1>& x,
										const stack<Tp1, Sequence1>& y);

			explicit stack(const Sequence& container = Sequence()) :
				c(container)
			{
			}

			stack(const stack& other) :
				c(other.c)
			{
			}

			~stack()
			{
			}

			stack&
			operator=(const stack& x)
			{
				if (this != &x)
				{
					c = x.c;
				}
				return *this;
			}

			bool
			empty()	const
			{
				return c.empty();
			}
			size_type
			size() const
			{
				return c.size();
			}
			value_type&
			top()
			{
				return c.back();
			}
			const value_type&
			top() const
			{
				return c.back();
			}
			void
			push(const value_type& x)
			{
				c.push_back(x);
			}
			void
			pop()
			{
				c.pop_back();
			}

		protected :

			Sequence c;
	};

	/* Purpose of inline functions :

	The inline functions are a C++ enhancement feature to increase the execution time of a program.
	Functions can be instructed to compiler to make them inline so that compiler can replace those function definition wherever those are being called.
	Inline functions are commonly used when the function definitions are small, and the functions are called several times in a program.
	Using inline functions saves time to transfer the control of the program from the calling function to the definition of the called function. */

	template<typename Tp, typename Sequence>
	inline bool
	operator==(const stack<Tp, Sequence>& x, const stack<Tp, Sequence>& y)
	{
		return x.c == y.c;
	}

	template<typename Tp, typename Sequence>
	inline bool
	operator<(const stack<Tp, Sequence>& x, const stack<Tp, Sequence>& y)
	{
		return x.c < y.c;
	}

	template<typename Tp, typename Sequence>
	inline bool
	operator!=(const stack<Tp, Sequence>& x, const stack<Tp, Sequence>& y)
	{
		return x.c != y.c;
	}

	template<typename Tp, typename Sequence>
	inline bool
	operator>(const stack<Tp, Sequence>& x, const stack<Tp, Sequence>& y)
	{
		return x.c > y.c;
	}

	template<typename Tp, typename Sequence>
	inline bool
	operator>=(const stack<Tp, Sequence>& x, const stack<Tp, Sequence>& y)
	{
		return x.c >= y.c;
	}

	template<typename Tp, typename Sequence>
	inline bool
	operator<=(const stack<Tp, Sequence>& x, const stack<Tp, Sequence>& y)
	{
		return x.c <= y.c;
	}
}

#endif