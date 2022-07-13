#include "test_map.hpp"

/* pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;
	pair<iterator,iterator>					equal_range (const key_type& k); */

static int test_count = 0;

typedef ft::pair<ft::map<TP1,TP2>::iterator,ft::map<TP1,TP2>::iterator> 	ft_eq;
typedef std::pair<std::map<TP1,TP2>::iterator,std::map<TP1,TP2>::iterator> 	std_eq;

void
equal_range_map_test()
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
	ft_eq	ft_rtvl;
	std_eq	std_rtvl;
	ft_rtvl = ft_map.equal_range(500);
	std_rtvl = std_map.equal_range(500);
	ft_output.push_back(ft_rtvl.first->first);
	ft_output.push_back(ft_rtvl.second->second);
	std_output.push_back(std_rtvl.first->first);
	std_output.push_back(std_rtvl.second->second);
	verify_content(ft_output, std_output, ++test_count);
	ft_rtvl = ft_map.equal_range(1);
	std_rtvl = std_map.equal_range(1);
	ft_output.push_back(ft_rtvl.first->first);
	ft_output.push_back(ft_rtvl.second->second);
	std_output.push_back(std_rtvl.first->first);
	std_output.push_back(std_rtvl.second->second);
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
	FT_MAP	ft_map;
	STD_MAP	std_map;
    for (int i = 0; i < 10000; ++i)
	{
		ft_map.insert(ft::make_pair(i, i));
		std_map.insert(std::make_pair(i, i));
	}
    srand(time(NULL));
	measure_handler(ft_map, std_map, &equal_range_speed_test, &equal_range_speed_test);
	equal_range_map_test();
    return 0;
}