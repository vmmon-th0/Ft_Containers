#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft
{
	template<bool B, typename Tp = void>
	struct enable_if
	{
	};

	template<typename Tp>
	struct enable_if<true, Tp> 
	{
		typedef Tp type;
	};
}

#endif