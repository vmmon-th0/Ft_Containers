#include "test_vector.hpp"

static int test_count = 0;

void
size_vector_test()
{
	while (++test_count <= 3)
	{
        size_t r = 0;
		FT_VECTOR       ft_vec(r, r);
		STD_VECTOR      std_vec(r, r);
        r = rand() % 500;
		verify_content(ft_vec, std_vec, test_count);
	}
}

template<typename ContainerType>
void
size_speed_test(ContainerType& x)
{
	x.size();
}

void
intro()
{
	std::cout << "==============================size==========================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec(1000000,1);
	STD_VECTOR std_vec(1000000,1);
    srand(time(NULL));
	measure_handler(ft_vec, std_vec, &size_speed_test, &size_speed_test);
	size_vector_test();
    return 0;
}