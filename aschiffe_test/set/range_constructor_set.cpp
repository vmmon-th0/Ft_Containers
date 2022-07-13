#include "test_set.hpp"

/* template <class InputIterator>
	set (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()); */

STD_SET		set_test;
static int	test_count = 0;

void
range_constructor_map_test()
{
	FT_SET	ft_set(set_test.begin(), set_test.end());
	STD_SET	std_set(set_test.begin(), set_test.end());
	verify_content(ft_set, std_set, ++test_count);
}

template<typename ContainerType>
void
range_constructor_speed_test(ContainerType& x)
{
	(void)x;
	ContainerType test(set_test.begin(), set_test.end());
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
	fill_random(set_test);
}

int
start()
{
	intro();
	init_global();
	FT_SET	ft_set;
	STD_SET	std_set;
    srand(time(NULL));
	measure_handler(ft_set, std_set, &range_constructor_speed_test, &range_constructor_speed_test);
	range_constructor_map_test();
    return 0;
}