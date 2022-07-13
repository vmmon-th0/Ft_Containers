#include "test_map.hpp"

/* void clear(); */

static int test_count = 0;

void
clear_map_test()
{
	FT_MAP		ft_map;
	STD_MAP		std_map;
	std_fill_random(std_map);
	ft_fill_random(ft_map);
	ft_map.clear();
	std_map.clear();
	verify_content(ft_map, std_map, ++test_count);
}

template<typename ContainerType>
void
clear_speed_test(ContainerType& x)
{
    x.clear();
}

void
intro()
{
	std::cout << "==============================clear=========================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_MAP		ft_map;
	STD_MAP		std_map;
	for (int i = 0; i < 1000000; ++i)
	{
		ft_map.insert(ft::make_pair(i, i));
		std_map.insert(std::make_pair(i, i));
	}
	srand(time(NULL));
	measure_handler(ft_map, std_map, &clear_speed_test, &clear_speed_test);
	clear_map_test();
	return 0;
}