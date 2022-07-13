#include "test_map.hpp"

/* (2) iterator erase (iterator position); */

static int test_count = 0;

void
key_erase_map_test()
{
	FT_MAP	ft_map;
	STD_MAP	std_map;
	ft_fill_random(ft_map);
    std_fill_random(std_map);
    srand(time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		int f = rand() % 1500;
		ft_map.erase(f);
		std_map.erase(f);
	}
	verify_content(ft_map, std_map, ++test_count);
	for (int i = 0; i < 20; ++i)
	{
		int f = rand() % 1500;
		ft_map.erase(f);
		std_map.erase(f);
	}
	verify_content(ft_map, std_map, ++test_count);
	for (int i = 0; i < 30; ++i)
	{
		int f = rand() % 1500;
		ft_map.erase(f);
		std_map.erase(f);
	}
	verify_content(ft_map, std_map, ++test_count);
}

template<typename ContainerType>
void
key_erase_speed_test(ContainerType& x)
{
    x.erase(rand() % 1500);
}

void
intro()
{
	std::cout << "==============================key_erase=====================================" << std::endl
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
	measure_handler(ft_map, std_map, &key_erase_speed_test, &key_erase_speed_test);
	key_erase_map_test();
	return 0;
}