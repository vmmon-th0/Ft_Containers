#include "test_set.hpp"

/*	range(3)
		template <class InputIterator>
			void insert (InputIterator first, InputIterator last); */

static int test_count = 0;

STD_SET		std_set_test;
FT_SET       ft_set_test;

void
range_insert_set_test()
{
	FT_SET	ft_set;
	STD_SET	std_set;
	ft_set.insert(ft_set_test.begin(), ft_set_test.end());
	std_set.insert(std_set_test.begin(), std_set_test.end());
	verify_content(ft_set, std_set, ++test_count);
}

template<typename ContainerType>
void
ft_single_insert_speed_test(ContainerType& x)
{
	x.insert(++test_count);
}

template<typename ContainerType>
void
std_single_insert_speed_test(ContainerType& x)
{
	x.insert(++test_count);
}

void
init_global()
{
    fill_random(ft_set_test);
	fill_random(std_set_test);
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
	FT_SET	ft_set;
	STD_SET std_set;
	srand(time(NULL));
	init_global();
	measure_handler(ft_set, std_set, &ft_single_insert_speed_test, &std_single_insert_speed_test);
	test_count = 0;
	range_insert_set_test();
	return 0;
}