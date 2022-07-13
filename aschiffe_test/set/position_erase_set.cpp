#include "test_set.hpp"

/* (1) void erase (iterator position); */

static int test_count = 0;

void
position_erase_set_test()
{
	FT_SET	ft_set;
	STD_SET	std_set;
	fill_random(ft_set);
    fill_random(std_set);
    for (int i = 0; i < 50; ++i)
    {
        ft_set.erase(ft_set.begin());
        std_set.erase(std_set.begin());
    }
	verify_content(ft_set, std_set, ++test_count);
}

template<typename ContainerType>
void
position_erase_speed_test(ContainerType& x)
{
    for (int i = 0; i < 10; ++i)
    {
        x.erase(x.begin());
    }
}

void
intro()
{
	std::cout << "==============================position_erase================================" << std::endl
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
	measure_handler(ft_set, std_set, &position_erase_speed_test, &position_erase_speed_test);
	position_erase_set_test();
	return 0;
}