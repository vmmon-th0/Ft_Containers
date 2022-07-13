#include "test_vector.hpp"

/* void pop_back (const value_type& val); */

static int test_count = 0;

void
pop_back_vector_test()
{
	FT_VECTOR	ft_vec;
	STD_VECTOR	std_vec;
	for (int i = 0; i < 25; ++i)
	{
		size_t k = rand() % 250;
		ft_vec.push_back(k);
		std_vec.push_back(k);
	}
	ft_vec.pop_back();
	std_vec.pop_back();
	verify_content(ft_vec, std_vec, ++test_count);
	for (int i = 0; i < 23; ++i)
	{
		ft_vec.pop_back();
		std_vec.pop_back();
	}
	verify_content(ft_vec, std_vec, ++test_count);
}

template<typename ContainerType>
void
pop_back_speed_test(ContainerType& x)
{
	for (int i = 0; i < 10; ++i)
	{
		x.pop_back();
	}
}

void
intro()
{
	std::cout << "==============================pop_back======================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec(10000, 1);
	STD_VECTOR std_vec(10000, 1);
    srand(time(NULL));
	measure_handler(ft_vec, std_vec, &pop_back_speed_test, &pop_back_speed_test);
	pop_back_vector_test();
    return 0;
}