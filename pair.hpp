#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{

	template<typename Tp1, typename Tp2>
	struct pair
	{
		typedef Tp1 first_type;
		typedef Tp2 second_type;

		Tp1 first;
		Tp2 second;

		pair()
		{
		}
		
		pair(const Tp1& x, const Tp2& y) :
			first(x),
			second(y)
		{
		}

		~pair()
		{
		}
	};

	template<typename Tp1, typename Tp2>
	inline bool
	operator==(const pair<Tp1, Tp2>& x, const pair<Tp1, Tp2>& y)
	{
		return x.first == y.first && x.second == y.second;
	}

	template<typename Tp1, typename Tp2>
	inline bool
	operator<(const pair<Tp1, Tp2>& x, const pair<Tp1, Tp2>& y)
	{
		return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
	}

	template<typename Tp1, typename Tp2>
	inline pair<Tp1, Tp2>
	make_pair(Tp1 x, Tp2 y)
	{
		return pair<Tp1, Tp2>(x, y);
	}
}

#endif
