#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <list>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>

/* CheatSheet of differents Types of iterators supported by STL CONTAINERS

	Vector 		: 	Random - Access
	List		:	Bidirectional
	Deque		:	Random - Access
	Map			:	Bidirectional
	Multimap	:	Bidirectional
	Set			:	Bidirectional
	Multiset	:	Bidirectional
	Stack		:	No iterator supported
	Queue		:	No iterator supported
	Priority-Q. :	No iterator supported

*/

/* https://www.cplusplus.com/reference/iterator/ */

namespace ft
{
	/* Iterators tags */

	struct input_iterator_tag { };

	struct output_iterator_tag { };

	struct forward_iterator_tag : public input_iterator_tag { };

	struct bidirectional_iterator_tag : public forward_iterator_tag { };

	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template<typename Category, typename Tp, typename Distance = std::ptrdiff_t, typename Pointer = Tp*, typename Reference = Tp&>
	struct iterator
	{
		typedef Category  iterator_category;
		typedef Tp        value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
	};

	/* Primary Template */

	/* If Iter does not have all five member types difference_type, value_type, pointer, reference,
	and iterator_category, then this template has no members by any of those names (ft::iterator_traits is SFINAE-friendly) */

	template<typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::difference_type   difference_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
	};

	/* Partial specialization for pointer types. */

	template<typename Tp>
	struct iterator_traits<Tp*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef Tp*							pointer;
		typedef Tp&							reference;
	};

	/* Partial specializations for const pointer types. */

	template<typename Tp>
	struct iterator_traits<const Tp*>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef const Tp*					pointer;
		typedef const Tp&					reference;
	};

	template<typename Tp>
	struct iterator_traits<Tp* const>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef Tp							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef const Tp*					pointer;
		typedef const Tp&					reference;
	};
}

#endif