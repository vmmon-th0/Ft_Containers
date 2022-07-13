#ifndef TYPES_HPP
#define TYPES_HPP

#include "enable_if.hpp"
#include "iterator_traits.hpp"

namespace ft
{
	template<typename Tp, Tp v>
	struct integral_constant
	{
		typedef Tp value_type;
		typedef integral_constant<Tp, v> type;

		static const Tp value = v;

		operator value_type() const
		{
			return v;
		}
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template<typename Tp>
	struct is_integral : public false_type
	{};

	template<typename Tp>
	struct is_integral<const Tp> : public is_integral<Tp>
	{};

	/* The volatile keyword is a type qualifier used to declare that an object can be modified in the program by something such as the operating system,
	the hardware, or a concurrently executing thread. (c) MSDN C++ Reference. */

	template<typename Tp>
	struct is_integral<volatile Tp> : public is_integral<Tp>
	{};

	template<typename Tp>
	struct is_integral<volatile const Tp> : public is_integral<Tp>
	{};

	template<>
	struct is_integral<char> : public true_type
	{};

	template<>
	struct is_integral<bool> : public true_type
	{};

	template<>
	struct is_integral<int> : public true_type
	{};

	template<>
	struct is_integral<long> : public true_type
	{};

	template<>
	struct is_integral<long long> : public true_type
	{};

	template<>
	struct is_integral<short> : public true_type
	{};

	template<>
	struct is_integral<wchar_t> : public true_type
	{};

	template<>
	struct is_integral<unsigned char> : public true_type
	{};

	template<>
	struct is_integral<unsigned int> : public true_type
	{};

	template<>
	struct is_integral<unsigned long> : public true_type
	{};

	template<>
	struct is_integral<unsigned long long> : public true_type
	{};

	template<>
	struct is_integral<unsigned short> : public true_type
	{};

}

#endif