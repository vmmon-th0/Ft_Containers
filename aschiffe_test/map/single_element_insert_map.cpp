#include "test_map.hpp"

/* pair<iterator,bool> insert (const value_type& val); */

static int test_count = 0;

STD_MAP		std_map_test;
FT_MAP      ft_map_test;

void
single_insert_map_test()
{
	FT_MAP	ft_map;
	STD_MAP	std_map;
	for (int i = 0; i < 10000; ++i)
	{
		ft_map.insert(ft::make_pair(i, i));
		std_map.insert(std::make_pair(i, i));
	}
	verify_content(ft_map, std_map, ++test_count);
}

template<typename ContainerType>
void
ft_single_insert_speed_test(ContainerType& x)
{
	for (int i = 0; i < 1000; ++i)
	{
		x.insert(ft::make_pair(++test_count, 1));	
	}
}

template<typename ContainerType>
void
std_single_insert_speed_test(ContainerType& x)
{
	for (int i = 0; i < 1000; ++i)
	{
		x.insert(std::make_pair(++test_count, 1));	
	}
}

void
init_global()
{
    ft_fill_random(ft_map_test);
	std_fill_random(std_map_test);
}

void
intro()
{
	std::cout << "==============================single_insert=================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_MAP ft_map;
	STD_MAP std_map;
	srand(time(NULL));
	init_global();
	measure_handler(ft_map, std_map, &ft_single_insert_speed_test, &std_single_insert_speed_test);
	test_count = 0;
	single_insert_map_test();
	return 0;
}