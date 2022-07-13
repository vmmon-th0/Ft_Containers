#include "test_vector.hpp"

/* void push_back (const value_type& val); */

static int test_count = 0;

void
push_back_vector_test()
{
	FT_VECTOR	ft_vec;
	STD_VECTOR	std_vec;
	for (int i = 0; i < 25; ++i)
	{
		size_t k = rand() % 250;
		ft_vec.push_back(k);
		std_vec.push_back(k);
	}
	verify_content(ft_vec, std_vec, ++test_count);
}

template<typename ContainerType>
void
push_back_speed_test(ContainerType& x)
{
	for (int i = 0; i < 10000; ++i)
	{
		x.push_back(i);
	}
}

void
intro()
{
	std::cout << "==============================push_back=====================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec;
	STD_VECTOR std_vec;
    srand(time(NULL));
	measure_handler(ft_vec, std_vec, &push_back_speed_test, &push_back_speed_test);
	push_back_vector_test();
    return 0;
}