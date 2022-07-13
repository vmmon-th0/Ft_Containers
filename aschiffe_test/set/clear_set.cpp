#include "test_set.hpp"

/* void clear(); */

static int test_count = 0;

void
clear_set_test()
{
	FT_SET		ft_set;
	STD_SET		std_set;
	fill_random(std_set);
	fill_random(ft_set);
	ft_set.clear();
	std_set.clear();
	verify_content(ft_set, std_set, ++test_count);
}

template<typename ContainerType>
void
clear_speed_test(ContainerType& x)
{
    x.clear();
}

void
intro()
{
	std::cout << "==============================clear=========================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_SET		ft_set;
	STD_SET		std_set;
	for (int i = 0; i < 1000000; ++i)
	{
		ft_set.insert(i);
		std_set.insert(i);
	}
	srand(time(NULL));
	measure_handler(ft_set, std_set, &clear_speed_test, &clear_speed_test);
	clear_set_test();
	return 0;
}