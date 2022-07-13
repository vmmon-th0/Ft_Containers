#include "test_set.hpp"

/* pair<iterator,iterator> equal_range (const value_type& val) const; */

static int test_count = 0;

typedef ft::pair<ft::set<TP>::iterator,ft::set<TP>::iterator>       ft_eq;
typedef std::pair<std::set<TP>::iterator,std::set<TP>::iterator> 	std_eq;

void
equal_range_set_test()
{
	FT_SET	ft_set;
	STD_SET	std_set;
	STD_VECTOR ft_output;
	STD_VECTOR std_output;
	for (int i = 0; i < 1000; ++i)
	{
		ft_set.insert(i);
		std_set.insert(i);
	}
	ft_eq	ft_rtvl;
	std_eq	std_rtvl;
	ft_rtvl = ft_set.equal_range(500);
	std_rtvl = std_set.equal_range(500);

	ft_output.push_back(*ft_rtvl.first);
	ft_output.push_back(*ft_rtvl.second);
	std_output.push_back(*std_rtvl.first);
	std_output.push_back(*std_rtvl.second);
	verify_content(ft_output, std_output, ++test_count);
	ft_rtvl = ft_set.equal_range(1);
	std_rtvl = std_set.equal_range(1);
	ft_output.push_back(*ft_rtvl.first);
	ft_output.push_back(*ft_rtvl.second);
	std_output.push_back(*std_rtvl.first);
	std_output.push_back(*std_rtvl.second);
	verify_content(ft_output, std_output, ++test_count);
}

template<typename ContainerType>
void
equal_range_speed_test(ContainerType& x)
{
    x.equal_range(500);
}

void
intro()
{
	std::cout << "==============================equal_range===================================" << std::endl
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
	measure_handler(ft_set, std_set, &equal_range_speed_test, &equal_range_speed_test);
	equal_range_set_test();
    return 0;
}