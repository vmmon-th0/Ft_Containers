#include "test_vector.hpp"

/* void clear(); */

static int test_count = 0;

void
clear_vector_test()
{
	FT_VECTOR ft_vec;
	STD_VECTOR std_vec;

	for (int i = 0; i < 100; ++i)
	{
		size_t k = rand() % 100;
		ft_vec.push_back(k);
		std_vec.push_back(k);
	}
    ft_vec.clear();
    std_vec.clear();
	verify_content(ft_vec, std_vec, ++test_count);
}

template<typename ContainerType>
void
clear_speed_test(ContainerType& x)
{
    x.clear();
}

void
intro()
{
	std::cout << "==============================clear=========================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec(10000, 1);
	STD_VECTOR std_vec(10000, 1);
	srand(time(NULL));
	measure_handler(ft_vec, std_vec, &clear_speed_test, &clear_speed_test);
	clear_vector_test();
	return 0;
}