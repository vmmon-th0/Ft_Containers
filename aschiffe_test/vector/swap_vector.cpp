#include "test_vector.hpp"

/* void swap (vector& x); */

static int test_count = 0;

FT_VECTOR	ft_test;
STD_VECTOR	std_test;

void
swap_vector_test()
{
	FT_VECTOR ft_vec;
	STD_VECTOR std_vec;
	for (int i = 0; i < 100; ++i)
	{
		size_t k = rand() % 100;
		ft_vec.push_back(k);
		std_vec.push_back(k);
	}
	ft_vec.swap(ft_test);
	std_vec.swap(std_test);
	verify_content(ft_vec, std_vec, ++test_count);
	ft_vec.push_back(123);
	std_vec.push_back(123);
	ft_vec.swap(ft_test);
	std_vec.swap(std_test);
	ft_vec.swap(ft_test);
	std_vec.swap(std_test);
	verify_content(ft_vec, std_vec, ++test_count);
}

template<typename ContainerType>
void
ft_swap_speed_test(ContainerType& x)
{
    x.swap(ft_test);
}

template<typename ContainerType>
void
std_swap_speed_test(ContainerType& x)
{
	x.swap(std_test);
}

void
init_global()
{
	for (int i = 0; i < 100; ++i)
	{
		size_t k = rand() % 50;
		ft_test.push_back(k);
		std_test.push_back(k);
	}
}

void
intro()
{
	std::cout << "==============================swap==========================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec(100, 1);
	STD_VECTOR std_vec(100, 1);
	srand(time(NULL));
	init_global();
	measure_handler(ft_vec, std_vec, &ft_swap_speed_test, &std_swap_speed_test);
	swap_vector_test();
	return 0;
}