#include "test_map.hpp"

/*	range(3)
		template <class InputIterator>
			void insert (InputIterator first, InputIterator last); */

static int test_count = 0;

STD_MAP		std_map_test;
FT_MAP      ft_map_test;

void
range_insert_map_test()
{
	FT_MAP	ft_map;
	STD_MAP	std_map;
	ft_map.insert(ft_map_test.begin(), ft_map_test.end());
	std_map.insert(std_map_test.begin(), std_map_test.end());
	verify_content(ft_map, std_map, ++test_count);
}

template<typename ContainerType>
void
ft_single_insert_speed_test(ContainerType& x)
{
	x.insert(ft::make_pair(++test_count, 1));
}

template<typename ContainerType>
void
std_single_insert_speed_test(ContainerType& x)
{
	x.insert(std::make_pair(++test_count, 1));
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
	range_insert_map_test();
	return 0;
}