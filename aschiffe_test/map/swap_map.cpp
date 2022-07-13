#include "test_map.hpp"

/* void swap (map& x); */

static int test_count = 0;

FT_MAP	ft_test;
STD_MAP std_test;

void
swap_map_test()
{
	FT_MAP ft_map;
	STD_MAP std_map;
	ft_fill_random(ft_map);
    std_fill_random(std_map);
	ft_map.swap(ft_test);
	std_map.swap(std_test);
	verify_content(ft_map, std_map, ++test_count);
    for (int i = 0; i < 10; ++i)
    {
        ft_map.insert(ft::make_pair(i, i));
        std_map.insert(std::make_pair(i, i));
    }
	ft_map.swap(ft_test);
	std_map.swap(std_test);
	ft_map.swap(ft_test);
	std_map.swap(std_test);
	verify_content(ft_map, std_map, ++test_count);
}

template<typename ContainerType>
void
ft_swap_speed_test(ContainerType& x)
{
    x.swap(ft_test);
}

template<typename ContainerType>
void
std_swap_speed_test(ContainerType& x)
{
	x.swap(std_test);
}

void
init_global()
{
	ft_fill_random(ft_test);
    std_fill_random(std_test);
}

void
intro()
{
	std::cout << "==============================swap==========================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_MAP	ft_map;
	STD_MAP std_map;
	for (int i = 0; i < 1000; ++i)
	{
		ft_map.insert(ft::make_pair(i, i));
		std_map.insert(std::make_pair(i, i));
	}
	srand(time(NULL));
	init_global();
	measure_handler(ft_map, std_map, &ft_swap_speed_test, &std_swap_speed_test);
	swap_map_test();
	return 0;
}