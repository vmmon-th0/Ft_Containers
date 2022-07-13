#include "test_set.hpp"

/* pair<iterator,bool> insert (const value_type& val); */

static int test_count = 0;

STD_SET     std_set_test;
FT_SET      ft_set_test;

void
single_insert_set_test()
{
	FT_SET	ft_set;
	STD_SET	std_set;
	for (int i = 0; i < 10000; ++i)
	{
		ft_set.insert(i);
		std_set.insert(i);
	}
	verify_content(ft_set, std_set, ++test_count);
}

template<typename ContainerType>
void
ft_single_insert_speed_test(ContainerType& x)
{
	for (int i = 0; i < 1000; ++i)
	{
		x.insert(++test_count);	
	}
}

template<typename ContainerType>
void
std_single_insert_speed_test(ContainerType& x)
{
	for (int i = 0; i < 1000; ++i)
	{
		x.insert(++test_count);	
	}
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
	FT_SET  ft_set;
	STD_SET std_set;
	srand(time(NULL));
	init_global();
	measure_handler(ft_set, std_set, &ft_single_insert_speed_test, &std_single_insert_speed_test);
	test_count = 0;
	single_insert_set_test();
	return 0;
}