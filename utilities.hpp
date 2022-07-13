#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include "iterator_traits.hpp"
#include <typeinfo>

namespace ft
{
	template<typename Iter>
	typename iterator_traits<Iter>::difference_type
	distance(Iter first, Iter last)
	{
		typename iterator_traits<Iter>::difference_type n = 0;
		while(first++ != last)
		{
			++n;
		}
		return n;
	}

	template<typename Tp>
	struct less
	{
		bool
		operator()(const Tp& lhs, const Tp& rhs) const
		{
			return lhs < rhs;
		}
	};

	template<typename Tp>
	void
	swap(Tp& x, Tp& y)
	{
		Tp tmp(x);
		x = y;
		y = tmp;
	}

	template<typename Tp> 
	const Tp&
	max(const Tp& x, const Tp& y)
	{
		return (x < y) ? y : x;
	}

	template<typename Tp>
	Tp
	init_page_size()
	{
		return ft::max(Tp(1), Tp(4096 / sizeof(Tp)));
	}

}

#endif