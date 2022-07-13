#include "test_set.hpp"

/* (2) size_type erase (const value_type& val); */

static int test_count = 0;

void
key_erase_set_test()
{
	FT_SET	ft_set;
	STD_SET	std_set;
	fill_random(ft_set);
    fill_random(std_set);
    srand(time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		int f = rand() % 1500;
		ft_set.erase(f);
		std_set.erase(f);
	}
	verify_content(ft_set, std_set, ++test_count);
	for (int i = 0; i < 20; ++i)
	{
		int f = rand() % 1500;
		ft_set.erase(f);
		std_set.erase(f);
	}
	verify_content(ft_set, std_set, ++test_count);
	for (int i = 0; i < 30; ++i)
	{
		int f = rand() % 1500;
		ft_set.erase(f);
		std_set.erase(f);
	}
	verify_content(ft_set, std_set, ++test_count);
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
	FT_SET	ft_set;
	STD_SET	std_set;
	fill_random(ft_set);
	fill_random(std_set);
	srand(time(NULL));
	measure_handler(ft_set, std_set, &key_erase_speed_test, &key_erase_speed_test);
	key_erase_set_test();
	return 0;
}