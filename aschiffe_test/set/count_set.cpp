#include "test_set.hpp"

/* size_type count (const value_type& val) const; */

static int test_count = 0;

void
count_set_test()
{
	FT_SET	    ft_set;
	STD_SET	    std_set;
    STD_VECTOR  ft_output;
    STD_VECTOR  std_output;
	for (int i = 0; i < 10000; ++i)
	{
		ft_set.insert(i);
		std_set.insert(i);
	}
    ft_output.push_back(ft_set.count(500));
    std_output.push_back(std_set.count(500));
    verify_content(ft_output, std_output, ++test_count);
    ft_output.push_back(ft_set.count(100001));
    std_output.push_back(std_set.count(100001));
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
	FT_SET	ft_set;
	STD_SET	std_set;
    for (int i = 0; i < 10000; ++i)
	{
		ft_set.insert(i);
		std_set.insert(i);
	}
    srand(time(NULL));
	measure_handler(ft_set, std_set, &count_speed_test, &count_speed_test);
	count_set_test();
    return 0;
}