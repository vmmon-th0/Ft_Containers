#include "test_map.hpp"

/* template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()); */

STD_MAP		map_test;
static int	test_count = 0;

void
range_constructor_map_test()
{
	FT_MAP	ft_map(map_test.begin(), map_test.end());
	STD_MAP	std_map(map_test.begin(), map_test.end());
	verify_content(ft_map, std_map, ++test_count);
}

template<typename ContainerType>
void
range_constructor_speed_test(ContainerType& x)
{
	(void)x;
	ContainerType test(map_test.begin(), map_test.end());
}

void
intro()
{
	std::cout << "==============================range_constructor=============================" << std::endl
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
	FT_MAP	ft_map;
	STD_MAP	std_map;
    srand(time(NULL));
	measure_handler(ft_map, std_map, &range_constructor_speed_test, &range_constructor_speed_test);
	range_constructor_map_test();
    return 0;
}