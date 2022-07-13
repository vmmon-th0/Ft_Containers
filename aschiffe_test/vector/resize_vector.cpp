#include "test_vector.hpp"

static int test_count = 0;

void
resize_vector_test()
{
	while (++test_count <= 3)
	{
		size_t r = 0;
		FT_VECTOR	ft_vec(r, r);
		STD_VECTOR	std_vec(r, r);
		r = rand() % 250;
		ft_vec.resize(r);
		std_vec.resize(r);
		r = rand() % 500;
		verify_content(ft_vec, std_vec, test_count);
	}
	FT_VECTOR	ft_vec;
	STD_VECTOR	std_vec;
	ft_vec.resize(0);
	std_vec.resize(0);
	verify_content(ft_vec, std_vec, test_count);
	//ft_vec.resize(2147483646);
	//std_vec.resize(2147483646);
	verify_content(ft_vec, std_vec, test_count);
}

template<typename ContainerType>
void
resize_speed_test(ContainerType& x)
{
	x.resize(1000);
}

void
intro()
{
	std::cout << "==============================resize========================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec(100, 1);
	STD_VECTOR std_vec(100, 1);
    srand(time(NULL));
	measure_handler(ft_vec, std_vec, &resize_speed_test, &resize_speed_test);
	resize_vector_test();
    return 0;
}