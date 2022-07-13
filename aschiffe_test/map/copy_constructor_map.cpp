#include "test_map.hpp"

/* map (const map& x); */

static int test_count = 0;

STD_MAP		map_test;

void
copy_constructor_map_test()
{
	FT_MAP	ft_map;
	STD_MAP	std_map;
	ft_fill_random(ft_map);
	std_fill_random(std_map);
    FT_MAP	ft_map2(ft_map);
    STD_MAP	std_map2(std_map);
	verify_content(ft_map2, std_map2, ++test_count);
}

template<typename ContainerType>
void
copy_constructor_speed_test(ContainerType& x)
{
	ContainerType test(x);
}

void
intro()
{
	std::cout << "==============================copy_constructor==============================" << std::endl
																								<< std::endl;
}

void
init_global()
{
	std_fill_random(map_test);
}

int
start()
{
	intro();
	init_global();
	FT_MAP	ft_map(map_test.begin(), map_test.end());
	STD_MAP	std_map(map_test.begin(), map_test.end());
    srand(time(NULL));
	measure_handler(ft_map, std_map, &copy_constructor_speed_test, &copy_constructor_speed_test);
	copy_constructor_map_test();
    return 0;
}