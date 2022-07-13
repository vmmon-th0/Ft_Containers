#include "test_vector.hpp"

/* iterator erase (iterator first, iterator last); */

static int test_count = 0;

void
range_erase_vector_test()
{
	FT_VECTOR ft_vec;
	STD_VECTOR std_vec;

	for (int i = 0; i < 100; ++i)
	{
		size_t k = rand() % 100;
		ft_vec.push_back(k);
		std_vec.push_back(k);
	}
	ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 2);
	std_vec.erase(std_vec.begin(), std_vec.begin() + 2);
	verify_content(ft_vec, std_vec, ++test_count);
	ft_vec.erase(ft_vec.end() - 3, ft_vec.end() - 1);
	std_vec.erase(std_vec.end() - 3, std_vec.end() - 1);
	verify_content(ft_vec, std_vec, ++test_count);
	ft_vec.erase(ft_vec.begin(), ft_vec.end());
	std_vec.erase(std_vec.begin(), std_vec.end());
	verify_content(ft_vec, std_vec, ++test_count);
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
	FT_VECTOR ft_vec(50000, 1);
	STD_VECTOR std_vec(50000, 1);
	srand(time(NULL));
	measure_handler(ft_vec, std_vec, &range_erase_speed_test, &range_erase_speed_test);
	range_erase_vector_test();
	return 0;
}