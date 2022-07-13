#include "test_map.hpp"

/* (1) void erase (iterator position); */

static int test_count = 0;

void
position_erase_map_test()
{
	FT_MAP	ft_map;
	STD_MAP	std_map;
	ft_fill_random(ft_map);
    std_fill_random(std_map);
    for (int i = 0; i < 50; ++i)
    {
        ft_map.erase(ft_map.begin());
        std_map.erase(std_map.begin());
    }
	verify_content(ft_map, std_map, ++test_count);
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
	FT_MAP	ft_map;
	STD_MAP	std_map;
	ft_fill_random(ft_map);
	std_fill_random(std_map);
	srand(time(NULL));
	measure_handler(ft_map, std_map, &position_erase_speed_test, &position_erase_speed_test);
	position_erase_map_test();
	return 0;
}