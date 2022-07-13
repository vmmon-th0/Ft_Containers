#include "test_map.hpp"

/* iterator find (const key_type& k);
const_iterator find (const key_type& k) const; */

static int test_count = 0;

void
find_map_test()
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
	ft_rtvl = ft_map.find(500);
	std_rtvl = std_map.find(500);
	verify_content(ft_output, std_output, ++test_count);
}

template<typename ContainerType>
void
find_speed_test(ContainerType& x)
{
	x.find(500);
}

void
intro()
{
	std::cout << "==============================find==========================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_MAP	ft_map;
	STD_MAP	std_map;
    for (int i = 0; i < 10000; ++i)
	{
		ft_map.insert(ft::make_pair(i, i));
		std_map.insert(std::make_pair(i, i));
	}
    srand(time(NULL));
	measure_handler(ft_map, std_map, &find_speed_test, &find_speed_test);
	find_map_test();
    return 0;
}