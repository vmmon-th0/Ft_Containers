#include "test_vector.hpp"

static int test_count = 0;

void
reserve_vector_test()
{
	FT_VECTOR	ft_vec;
	STD_VECTOR	std_vec;
	for (int i = 0; i < 100; ++i)
	{
		size_t k = rand() % 1000;
		ft_vec.insert(ft_vec.begin(), k);
		std_vec.insert(std_vec.begin(), k);
	}
	ft_vec.reserve(1);
	std_vec.reserve(1);
	verify_content(ft_vec, std_vec, ++test_count);
	ft_vec.reserve(10000);
	std_vec.reserve(10000);
	ft_vec.insert(ft_vec.begin(), ft_vec.capacity());
	std_vec.insert(std_vec.begin(), std_vec.capacity());
	verify_content(ft_vec, std_vec, ++test_count);
}

template<typename ContainerType>
void
reserve_speed_test(ContainerType& x)
{
	x.reserve(10000);
}

void
intro()
{
	std::cout << "==============================reserve=======================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec(100, 1);
	STD_VECTOR std_vec(100, 1);
    srand(time(NULL));
	measure_handler(ft_vec, std_vec, &reserve_speed_test, &reserve_speed_test);
	reserve_vector_test();
    return 0;
}