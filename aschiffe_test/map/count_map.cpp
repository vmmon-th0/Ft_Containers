#include "test_map.hpp"

/* size_type count (const key_type& k) const; */

static int test_count = 0;

void
count_map_test()
{
    STD_VECTOR ft_output;
    STD_VECTOR std_output;
	FT_MAP	ft_map;
	STD_MAP	std_map;
	for (int i = 0; i < 10000; ++i)
	{
		ft_map.insert(ft::make_pair(i, i));
		std_map.insert(std::make_pair(i, i));
	}
    ft_output.push_back(ft_map.count(500));
    std_output.push_back(std_map.count(500));
    verify_content(ft_output, std_output, ++test_count);
    ft_output.push_back(ft_map.count(100001));
    std_output.push_back(std_map.count(100001));
	verify_content(ft_output, std_output, ++test_count);
}

template<typename ContainerType>
void
count_speed_test(ContainerType& x)
{
    x.count(rand() % 10000);
}

void
intro()
{
	std::cout << "==============================count=========================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_MAP	ft_map;
	STD_MAP	std_map;
    for (int i = 0; i < 10000; ++i)
	{
		ft_map.insert(ft::make_pair(i, i));
		std_map.insert(std::make_pair(i, i));
	}
    srand(time(NULL));
	measure_handler(ft_map, std_map, &count_speed_test, &count_speed_test);
	count_map_test();
    return 0;
}