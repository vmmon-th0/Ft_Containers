#include "test_vector.hpp"

/* assign operator = */

static int test_count = 0;
std::list<int> lst(10000, 1);

ft::vector<int> ft_test(1000, 1);
std::vector<int> std_test(1000, 1);

// Test to correct

void
assign_vector_test()
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
ft_assign_speed_test(ContainerType& x)
{
	(void)x;
	ContainerType y(10000, 1);
	y = ft_test;
}

template<typename ContainerType>
void
std_assign_speed_test(ContainerType& x)
{
	(void)x;
	ContainerType y(10000, 1);
	y = std_test;
}

void
intro()
{
	std::cout << std::endl << "==============================assign_operator==============================="	<< std::endl
																												<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR	ft_vec;
	STD_VECTOR	std_vec;
	srand(time(NULL));
	measure_handler(ft_vec, std_vec, &ft_assign_speed_test, &std_assign_speed_test);
	assign_vector_test();
	return 0;
}