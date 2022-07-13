#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft
{
	template<typename InputIt1, typename InputIt2>
	bool equal (InputIt1 beg1, InputIt1 end1, InputIt2 beg2)
	{
		while (beg1 != end1)
		{
			if (!(*beg1 == *beg2))
			{
				return false;
			}
			++beg1, ++beg2;
		}
		return true;
	}
}

#endif