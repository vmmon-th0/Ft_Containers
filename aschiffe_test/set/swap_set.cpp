#include "test_set.hpp"

/* void swap (set& x); */

static int test_count = 0;

FT_SET	ft_test;
STD_SET std_test;

void
swap_set_test()
{
	FT_SET ft_set;
	STD_SET std_set;
	fill_random(ft_set);
    fill_random(std_set);
	ft_set.swap(ft_test);
	std_set.swap(std_test);
	verify_content(ft_set, std_set, ++test_count);
    for (int i = 0; i < 10; ++i)
    {
        ft_set.insert(i);
		std_set.insert(i);
    }
	ft_set.swap(ft_test);
	std_set.swap(std_test);
	ft_set.swap(ft_test);
	std_set.swap(std_test);
	verify_content(ft_set, std_set, ++test_count);
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
	fill_random(ft_test);
    fill_random(std_test);
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
	FT_SET	ft_set;
	STD_SET std_set;
	for (int i = 0; i < 100000; ++i)
	{
		ft_set.insert(i);
		std_set.insert(i);
	}
	srand(time(NULL));
	init_global();
	measure_handler(ft_set, std_set, &ft_swap_speed_test, &std_swap_speed_test);
	swap_set_test();
	return 0;
}