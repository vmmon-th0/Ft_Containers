#include "test_set.hpp"

/* set (const set& x); */

static int test_count = 0;

STD_SET		set_test;

void
copy_constructor_set_test()
{
	FT_SET	ft_set;
	STD_SET	std_set;
	fill_random(ft_set);
	fill_random(std_set);
    FT_SET	ft_set2(ft_set);
    STD_SET	std_set2(std_set);
	verify_content(ft_set2, std_set2, ++test_count);
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
	fill_random(set_test);
}

int
start()
{
	intro();
	init_global();
	FT_SET	ft_set(set_test.begin(), set_test.end());
	STD_SET	std_set(set_test.begin(), set_test.end());
    srand(time(NULL));
	measure_handler(ft_set, std_set, &copy_constructor_speed_test, &copy_constructor_speed_test);
	copy_constructor_set_test();
    return 0;
}