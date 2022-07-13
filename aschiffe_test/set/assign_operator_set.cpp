#include "test_set.hpp"

static int test_count = 0;

FT_SET  ft_test;
STD_SET std_test;

void
assign_set_test()
{
	FT_SET	ft_set;
	STD_SET	std_set;
	for (int i = 0; i < 1000000; ++i)
	{
		ft_set.insert(i);
		std_set.insert(i);
	}
    FT_SET	ft_set2 = ft_test;
    STD_SET	std_set2 = std_test;
	verify_content(ft_set2, std_set2, ++test_count);
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
	fill_random(ft_test);
	fill_random(std_test);
}

int
start()
{
	intro();
	init_global();
	FT_SET		ft_set;
	STD_SET		std_set;
	srand(time(NULL));
	measure_handler(ft_set, std_set, &ft_assign_speed_test, &std_assign_speed_test);
	assign_set_test();
	return 0;
}