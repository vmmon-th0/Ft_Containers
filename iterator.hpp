#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include "types.hpp"
#include "iterator_traits.hpp"

template<typename Iterator, typename Container>
class normal_iterator;

namespace ft
{
	template<typename Iterator>
	class reverse_iterator : public iterator<	typename iterator_traits<Iterator>::iterator_category,
												typename iterator_traits<Iterator>::value_type,
												typename iterator_traits<Iterator>::difference_type,
												typename iterator_traits<Iterator>::pointer,
												typename iterator_traits<Iterator>::reference >
	{
		protected :

			Iterator 									_current;
			typedef 	ft::iterator_traits<Iterator>	traits_type;

		public :

			typedef Iterator								iterator_type;
			typedef typename traits_type::difference_type	difference_type;
			typedef typename traits_type::pointer			pointer;
			typedef typename traits_type::reference			reference;

			explicit reverse_iterator(Iterator rv = Iterator()) :
				_current(rv)
			{
			}

			template<typename Iter>
			reverse_iterator(const reverse_iterator<Iter>& rv) :
				_current(rv.base())
			{
			}	

			reverse_iterator(const reverse_iterator& rv) :
				_current(rv._current)
			{
			}

			template <typename Iter>
			reverse_iterator&
			operator=(const reverse_iterator<Iter>& x)
			{
				_current = x.base();
				return *this;
			}

			iterator_type
			base() const
			{
				return _current;
			}

			reference
			operator*() const
			{
				Iterator tmp = _current;
				return *--tmp;
			}

			pointer
			operator->() const
			{
				return &(operator*());
			}

			reverse_iterator&
			operator++()
			{
				--_current;
				return *this;
			}

			reverse_iterator
			operator++(int)
			{
				reverse_iterator tmp = *this;
				--_current;
				return tmp;
			}

			reverse_iterator&
			operator--()
			{
				++_current;
				return *this;
			}

			reverse_iterator
			operator--(int)
			{
				reverse_iterator tmp = *this;
				++_current;
				return tmp;
			}

			reverse_iterator
			operator+(difference_type n) const
			{
				return reverse_iterator(_current - n);
			}

			reverse_iterator&
			operator+=(difference_type n)
			{
				_current -= n;
				return *this;
			}

			reverse_iterator
			operator-(difference_type n) const
			{
				return reverse_iterator(_current + n);
			}

			reverse_iterator&
			operator-=(difference_type n)
			{
				_current += n;
				return *this;
			}

			reference
			operator[](difference_type n) const
			{
				return *(*this + n);
			}
	
	};

	template<typename Iterator>
	inline bool
	operator==(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename Iterator>
	inline bool
	operator<(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return rhs.base() < lhs.base();
	}

	template<typename Iterator>
	inline bool
	operator!=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename Iterator>
	inline bool
	operator>(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return rhs < lhs;
	}

	template<typename Iterator>
	inline bool
	operator<=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return !(rhs < lhs);
	}
		
	template<typename Iterator>
	inline bool
	operator>=(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return !(lhs < rhs);
	}

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator==(const reverse_iterator<IteratorL>& lhs,
		const reverse_iterator<IteratorR>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator<(const reverse_iterator<IteratorL>& lhs,
		const reverse_iterator<IteratorR>& rhs)
	{
		return rhs.base() < lhs.base();
	}

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator!=(const reverse_iterator<IteratorL>& lhs,
		const reverse_iterator<IteratorR>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator>(const reverse_iterator<IteratorL>& lhs,
		const reverse_iterator<IteratorR>& rhs)
	{
		return rhs < lhs;
	}

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator<=(const reverse_iterator<IteratorL>& lhs,
		const reverse_iterator<IteratorR>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename IteratorL, typename IteratorR>
	inline bool
	operator>=(const reverse_iterator<IteratorL>& lhs,
		const reverse_iterator<IteratorR>& rhs)
	{
		return !(lhs < rhs);
	}

	template<typename Iterator>
	inline typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y)
	{
		return y.base() - x.base();
	}

	template<typename IteratorL, typename IteratorR>
	inline typename reverse_iterator<IteratorL>::difference_type operator-(const reverse_iterator<IteratorL>& x, 
		const reverse_iterator<IteratorR>& y)
	{
		return y.base() - x.base();
	}

	template<typename Iterator>
	inline reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x)
	{
		return reverse_iterator<Iterator>(x.base() - n);
	}

	template <typename Iterator, typename Container>
	class normal_iterator
	{

		protected :

			Iterator   _current;
			typedef     ft::iterator_traits<Iterator> traits_type;

		public :

			typedef	Iterator		iterator_type;

			typedef typename traits_type::iterator_category		iterator_category;
			typedef typename traits_type::value_type			value_type;
			typedef typename traits_type::difference_type		difference_type;
			typedef typename traits_type::reference				reference;
			typedef typename traits_type::pointer				pointer;

			normal_iterator()	
				: _current(Iterator())
			{
			}

			explicit normal_iterator(pointer x) :
				_current(x)
			{
			}

			template<typename _Iter>											
			normal_iterator(const normal_iterator<_Iter, Container> &i ) :
				_current(i.base())
			{
			}

			operator normal_iterator<const Iterator, Container>() const
			{
				return (normal_iterator<const Iterator, Container>(this->_current));
			}

			reference
			operator*() const
			{
				return *_current;
			}

			pointer
			operator->() const
			{
				return _current;
			}

			normal_iterator&
			operator++()
			{
				++_current;
				return *this;
			}

			normal_iterator
			operator++(int)
			{
				return normal_iterator(_current++);
			}

			normal_iterator&
			operator--()
			{
				--_current;
				return *this;
			}

			normal_iterator
			operator--(int)
			{
				return normal_iterator(_current--);
			}

			reference
			operator[](const difference_type& n) const
			{
				return _current[n];
			}

			normal_iterator&
			operator+=(const difference_type& n)
			{
				_current += n;
				return *this;
			}

			normal_iterator
			operator+(const difference_type& n) const
			{
				return normal_iterator(_current + n);
			}

			normal_iterator&
			operator-=(const difference_type& n)
			{
				_current -= n;
				return *this;
			}

			normal_iterator
			operator-(const difference_type& n) const
			{
				return normal_iterator(_current - n);
			}

			normal_iterator
			operator=(const normal_iterator& x)
			{
				if (this != &x)
				{
					_current = x._current;
				}
				return *this;
			}

			const Iterator&
			base() const
			{
				return _current;
			}
	};

	/* Purpose of inline functions :

	The inline functions are a C++ enhancement feature to increase the execution time of a program.
	Functions can be instructed to compiler to make them inline so that compiler can replace those function definition wherever those are being called.
	Inline functions are commonly used when the function definitions are small, and the functions are called several times in a program.
	Using inline functions saves time to transfer the control of the program from the calling function to the definition of the called function. */

	/* Forward iterator requirements */

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool
	operator==(const normal_iterator<IteratorL, Container>& lhs,
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool
	operator==(const normal_iterator<Iterator, Container>& lhs,
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool
	operator!=(const normal_iterator<IteratorL, Container>& lhs,
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool
	operator!=(const normal_iterator<Iterator, Container>& lhs,
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool
	operator<(const normal_iterator<IteratorL, Container>& lhs,
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool
	operator<(const normal_iterator<Iterator, Container>& lhs,
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool
	operator>(const normal_iterator<IteratorL, Container>& lhs,
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool
	operator>(const normal_iterator<Iterator, Container>& lhs,
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() > rhs.base();
	}
	
	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool
	operator<=(const normal_iterator<IteratorL, Container>& lhs,
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<typename Iterator, typename Container>
	inline bool
	operator<=(const normal_iterator<Iterator, Container>& lhs,
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline bool
	operator>=(const normal_iterator<IteratorL, Container>& lhs,
		const normal_iterator<IteratorR, Container>& rhs)
	{
		return lhs.base() >= rhs.base();
	}
	
	template<typename Iterator, typename Container>
	inline bool
	operator>=(const normal_iterator<Iterator, Container>& lhs,
		const normal_iterator<Iterator, Container>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<typename IteratorL, typename IteratorR, typename Container>
	inline typename normal_iterator<IteratorL, Container>::difference_type operator-
	(const normal_iterator <IteratorL, Container>& lhs,
		const normal_iterator <IteratorR, Container>& rhs)
	{
		return lhs.base() - rhs.base();
	}

	template<typename Iterator, typename Container>
	inline typename normal_iterator<Iterator, Container>::difference_type operator-
	(const normal_iterator<Iterator, Container>& lhs,
		const normal_iterator <Iterator, Container>& rhs)
	{
		return lhs.base() - rhs.base();
	}

	template<typename Iterator, typename Container>
	inline normal_iterator<Iterator, Container> operator+ 
	(typename normal_iterator<Iterator, Container>::difference_type n,
		const normal_iterator<Iterator, Container>& i)
	{
		return normal_iterator<Iterator, Container>(i.base() + n);
	}

}

#endif