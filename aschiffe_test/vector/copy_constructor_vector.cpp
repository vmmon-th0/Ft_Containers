#include "test_vector.hpp"

/* copy(4)
    vector (const vector& x);
*/

static int test_count = 0;

FT_VECTOR z(10000, 1);
STD_VECTOR y(10000, 1);

void
copy_constructor_vector_test()
{
	while (++test_count <= 3)
	{
		int r = rand() % 5000;

		FT_VECTOR	ft_copy_vec(r, r);
		STD_VECTOR	std_copy_vec(r, r);

		FT_VECTOR	ft_vec(ft_copy_vec);
		STD_VECTOR	std_vec(std_copy_vec);
		verify_content(ft_vec, std_vec, test_count);
	}
}

template<typename ContainerType>
void
ft_copy_speed_test(ContainerType& x)
{
	(void)x;
	ContainerType test(z);
}

template<typename ContainerType>
void
std_copy_speed_test(ContainerType& x)
{
	(void)x;
	ContainerType test(y);
}

void
intro()
{
	std::cout << "==============================copy_constructor==============================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec(10000,1);
	STD_VECTOR std_vec(10000,1);
    srand(time(NULL));
	measure_handler(ft_vec, std_vec, &ft_copy_speed_test, &std_copy_speed_test);
	copy_constructor_vector_test();
    return 0;
}