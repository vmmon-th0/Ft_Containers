#include "test_set.hpp"

/* (3)	void erase (iterator first, iterator last); */

static int test_count = 0;

void
range_erase_set_test()
{
	FT_SET	ft_set;
	STD_SET	std_set;
	fill_random(ft_set);
    fill_random(std_set);
    ft_set.erase(ft_set.begin(), ft_set.end());
    std_set.erase(std_set.begin(), std_set.end());
	verify_content(ft_set, std_set, ++test_count);
}

template<typename ContainerType>
void
range_erase_speed_test(ContainerType& x)
{
    x.erase(x.begin(), x.end());
}

void
intro()
{
	std::cout << "==============================range_erase===================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_SET	ft_set;
	STD_SET	std_set;
	fill_random(ft_set);
	fill_random(std_set);
	srand(time(NULL));
	measure_handler(ft_set, std_set, &range_erase_speed_test, &range_erase_speed_test);
	range_erase_set_test();
	return 0;
}