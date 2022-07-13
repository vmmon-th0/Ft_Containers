#include "test_vector.hpp"

/* template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last); */

static int test_count = 0;

FT_VECTOR	ft_test;
STD_VECTOR	std_test;

void
range_insert_vector_test()
{
	FT_VECTOR	ft_vec;
	STD_VECTOR	std_vec;
	for (int i = 0; i < 100; ++i)
	{
        size_t j = rand() % 50;
		size_t pos = rand() % (i + 1);
		ft_vec.insert(ft_vec.begin() + pos, ft_test.begin(), ft_test.end() - j);
		std_vec.insert(std_vec.begin() + pos, std_test.begin(), std_test.end() - j);
	}
	verify_content(ft_vec, std_vec, ++test_count);
	ft_vec.insert(ft_vec.end(), ft_test.begin(), ft_test.end());
	std_vec.insert(std_vec.end(), std_test.begin(), std_test.end());
	verify_content(ft_vec, std_vec, ++test_count);
}

template<typename ContainerType>
void
ft_range_insert_speed_test(ContainerType& x)
{
	x.insert(x.begin(), ft_test.begin(), ft_test.end());
}

template<typename ContainerType>
void
std_range_insert_speed_test(ContainerType& x)
{
	x.insert(x.begin(), std_test.begin(), std_test.end());
}

void
init_global()
{
	for (int i = 0; i < 50; ++i)
	{
		size_t k = rand() % 50;
		ft_test.push_back(k);
		std_test.push_back(k);
	}
}

void
intro()
{
	std::cout << "==============================range_insert==================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec;
	STD_VECTOR std_vec;
	srand(time(NULL));
	init_global();
	measure_handler(ft_vec, std_vec, &ft_range_insert_speed_test, &std_range_insert_speed_test);
	range_insert_vector_test();
	return 0;
}