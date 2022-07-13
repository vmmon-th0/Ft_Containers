#include "test_map.hpp"

/* (3)	void erase (iterator first, iterator last); */

static int test_count = 0;

void
range_erase_map_test()
{
	FT_MAP	ft_map;
	STD_MAP	std_map;
	ft_fill_random(ft_map);
    std_fill_random(std_map);
    ft_map.erase(ft_map.begin(), ft_map.end());
    std_map.erase(std_map.begin(), std_map.end());
	verify_content(ft_map, std_map, ++test_count);
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
	FT_MAP	ft_map;
	STD_MAP	std_map;
	ft_fill_random(ft_map);
	std_fill_random(std_map);
	srand(time(NULL));
	measure_handler(ft_map, std_map, &range_erase_speed_test, &range_erase_speed_test);
	range_erase_map_test();
	return 0;
}