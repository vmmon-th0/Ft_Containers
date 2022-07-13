#include "test_map.hpp"

/* iterator lower_bound (const key_type& k);
	const_iterator lower_bound (const key_type& k) const; */

static int test_count = 0;

void
lower_bound_map_test()
{
	FT_MAP		ft_map;
	STD_MAP		std_map;
	STD_VECTOR ft_output;
	STD_VECTOR std_output;
	for (int i = 0; i < 10000; ++i)
	{
		ft_map.insert(ft::make_pair(i, i));
		std_map.insert(std::make_pair(i, i));
	}
	FT_MAP::iterator	    ft_rtvl;
	STD_MAP::iterator	    std_rtvl;
	ft_rtvl = ft_map.lower_bound(500);
	std_rtvl = std_map.lower_bound(500);
	verify_content(ft_output, std_output, ++test_count);
}

template<typename ContainerType>
void
lower_bound_speed_test(ContainerType& x)
{
	x.lower_bound(500);
}

void
intro()
{
	std::cout << "==============================lower_bound===================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_MAP	ft_map;
	STD_MAP	std_map;
    for (int i = 0; i < 1000; ++i)
	{
		ft_map.insert(ft::make_pair(i, i));
		std_map.insert(std::make_pair(i, i));
	}
    srand(time(NULL));
	measure_handler(ft_map, std_map, &lower_bound_speed_test, &lower_bound_speed_test);
	lower_bound_map_test();
    return 0;
}