#include "test_vector.hpp"

/* fill (2)	
explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()); */

static int test_count = 0;

void
fill_constructor_vector_test()
{
	while (++test_count <= 3)
	{
		int tmp = rand() % 4000;
		FT_VECTOR	ft_vec(tmp, 1);
		STD_VECTOR	std_vec(tmp, 1);
		verify_content(ft_vec, std_vec, test_count);
	}
}

template<typename ContainerType>
void
fill_speed_test(ContainerType& x)
{
	(void)x;
	ContainerType(100000, 1);
}

void
intro()
{
	std::cout << "==============================fill_constructor==============================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR	ft_vec;
	STD_VECTOR	std_vec;
	srand(time(NULL));
	measure_handler(ft_vec, std_vec, &fill_speed_test, &fill_speed_test);
	fill_constructor_vector_test();
	return 0;
}