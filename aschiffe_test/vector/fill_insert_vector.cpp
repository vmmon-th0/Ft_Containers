#include "test_vector.hpp"

/* void insert (iterator position, size_type n, const value_type& val); */

static int test_count = 0;

void
fill_insert_vector_test()
{
	FT_VECTOR	ft_vec;
	STD_VECTOR	std_vec;
	for (int i = 0; i < 100; ++i)
	{
		size_t k = rand() % 100;
        size_t fill = rand() % 50;
		size_t pos = rand() % (i + 1);
		ft_vec.insert(ft_vec.begin() + pos, fill, k);
		std_vec.insert(std_vec.begin() + pos, fill , k);
	}
	verify_content(ft_vec, std_vec, ++test_count);
	ft_vec.insert(ft_vec.end(), 5, 1);
	std_vec.insert(std_vec.end(), 5, 1);
	verify_content(ft_vec, std_vec, ++test_count);
	for (int i = 0; i < 5; ++i)
	{
		ft_vec.insert(ft_vec.end(), 5, 1);
		std_vec.insert(std_vec.end(), 5, 1);
	}
	verify_content(ft_vec, std_vec, ++test_count);
	ft_vec.insert(ft_vec.begin(), 1, 2);
	std_vec.insert(std_vec.begin(), 1, 2);
	for (int i = 0; i < 5; ++i)
	{
		ft_vec.insert(ft_vec.end(), i, 2);
		std_vec.insert(std_vec.end(), i, 2);
	}
	verify_content(ft_vec, std_vec, ++test_count);
}

template<typename ContainerType>
void
fill_insert_speed_test(ContainerType& x)
{
    x.insert(x.begin(), 10, 1);
}

void
intro()
{
	std::cout << "==============================fill_insert===================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec;
	STD_VECTOR std_vec;
    srand(time(NULL));
	measure_handler(ft_vec, std_vec, &fill_insert_speed_test, &fill_insert_speed_test);
	fill_insert_vector_test();
    return 0;
}