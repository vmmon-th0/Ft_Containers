#include "test_vector.hpp"

/*	range(3)
	template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type()); */

static int test_count = 0;
STD_LST lst(10000, 1);

void
range_constructor_vector_test()
{
	while (++test_count <= 3)
	{
		std::list<TP> lst(rand() % 5000, rand() % 5000);
		FT_VECTOR	ft_vec(lst.begin(), lst.end());
		STD_VECTOR	std_vec(lst.begin(), lst.end());
		verify_content(ft_vec, std_vec, test_count);
	}
}

template<typename ContainerType>
void
range_speed_test(ContainerType& x)
{
	(void)x;
	ContainerType(lst.begin(), lst.end());
}

void
intro()
{
	std::cout << "==============================range_constructor=============================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR	ft_vec;
	STD_VECTOR	std_vec;
	srand(time(NULL));
	measure_handler(ft_vec, std_vec, &range_speed_test, &range_speed_test);
	range_constructor_vector_test();
	return 0;
}