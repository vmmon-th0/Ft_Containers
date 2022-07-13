#include "test_map.hpp"

/* copy (1)	
 map& operator= (const map& x); */

static int test_count = 0;

FT_MAP  ft_test;
STD_MAP std_test;

void
assign_map_test()
{
	FT_MAP	ft_map;
	STD_MAP	std_map;
	for (int i = 0; i < 1000000; ++i)
	{
		ft_map.insert(ft::make_pair(i, i));
		std_map.insert(std::make_pair(i, i));
	}
    FT_MAP	ft_map2 = ft_test;
    STD_MAP	std_map2 = std_test;
	verify_content(ft_map2, std_map2, ++test_count);
}

template<typename ContainerType>
void
ft_assign_speed_test(ContainerType& x)
{
	x = ft_test;
}

template<typename ContainerType>
void
std_assign_speed_test(ContainerType& x)
{
	x = std_test;
}

void
intro()
{
	std::cout << std::endl << "==============================assign_operator==============================="	<< std::endl
																												<< std::endl;
}

void
init_global()
{
	ft_fill_random(ft_test);
	std_fill_random(std_test);
}

int
start()
{
	intro();
	init_global();
	FT_MAP		ft_map;
	STD_MAP		std_map;
	srand(time(NULL));
	measure_handler(ft_map, std_map, &ft_assign_speed_test, &std_assign_speed_test);
	assign_map_test();
	return 0;
}