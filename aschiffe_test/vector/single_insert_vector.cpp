#include "test_vector.hpp"

/* iterator insert (iterator position, const value_type& val); */

static int test_count = 0;

void
single_insert_vector_test()
{
	FT_VECTOR	ft_vec;
	STD_VECTOR	std_vec;
	for (int i = 0; i < 100; ++i)
	{
		size_t k = rand() % 100;
		size_t pos = rand() % (i + 1);
		ft_vec.insert(ft_vec.begin() + pos, k);
		std_vec.insert(std_vec.begin() + pos , k);
	}
	verify_content(ft_vec, std_vec, ++test_count);
	ft_vec.insert(ft_vec.end(), 1);
	std_vec.insert(std_vec.end(), 1);
	verify_content(ft_vec, std_vec, ++test_count);
	for (int i = 0; i < 5; ++i)
	{
		ft_vec.insert(ft_vec.end(), 1);
		std_vec.insert(std_vec.end(), 1);
	}
	verify_content(ft_vec, std_vec, ++test_count);
	ft_vec.insert(ft_vec.begin(), 2);
	std_vec.insert(std_vec.begin(), 2);
	for (int i = 0; i < 5; ++i)
	{
		ft_vec.insert(ft_vec.end(), 2);
		std_vec.insert(std_vec.end(), 2);
	}
	verify_content(ft_vec, std_vec, ++test_count);
}

template<typename ContainerType>
void
single_insert_speed_test(ContainerType& x)
{
    x.insert(x.begin(), 1);
}

void
intro()
{
	std::cout << "==============================single_insert=================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec;
	STD_VECTOR std_vec;
    srand(time(NULL));
	measure_handler(ft_vec, std_vec, &single_insert_speed_test, &single_insert_speed_test);
	single_insert_vector_test();
    return 0;
}