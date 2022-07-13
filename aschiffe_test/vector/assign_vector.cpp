#include "test_vector.hpp"

/* range (1)	
template <class InputIterator>
  void assign (InputIterator first, InputIterator last); */

/* fill (2)	
void assign (size_type n, const value_type& val); */

static int test_count = 0;

FT_VECTOR	ft_test;
STD_VECTOR	std_test;

void
assign_vector_test(bool option)
{
	FT_VECTOR	ft_vec;
	STD_VECTOR	std_vec;

	if (option == true)
	{
		ft_vec.assign(ft_test.begin(), ft_test.end());
		std_vec.assign(std_test.begin(), std_test.end());
		verify_content(ft_vec, std_vec, ++test_count);
		ft_vec.assign(ft_test.begin(), ft_test.begin() + 1);
		std_vec.assign(std_test.begin(), std_test.begin() + 1);
		verify_content(ft_vec, std_vec, ++test_count);
		ft_vec.assign(ft_test.end() - 1, ft_test.end() + 3);
		std_vec.assign(std_test.end() - 1, std_test.end() + 3);
		verify_content(ft_vec, std_vec, ++test_count);
	}
	test_count = 0;
	if (option == false)
	{
		ft_vec.assign(10000, 123);
		std_vec.assign(10000, 123);
		verify_content(ft_vec, std_vec, ++test_count);
		ft_vec.assign(100, 123);
		std_vec.assign(100, 123);
		verify_content(ft_vec, std_vec, ++test_count);
		ft_vec.assign(1, 123);
		std_vec.assign(1, 123);
		verify_content(ft_vec, std_vec, ++test_count);
	}
}

template<typename ContainerType>
void
range_assign_speed_test(ContainerType& x)
{
	x.assign(100000, 1);
}

template<typename ContainerType>
void
fill_assign_speed_test(ContainerType& x)
{
	x.assign(100000, 1);
}

void
init_global()
{
	for (int i = 0; i < 100; ++i)
	{
		size_t k = rand() % 50;
		ft_test.push_back(k);
		std_test.push_back(k);
	}
}

void
intro()
{
	std::cout << "==============================assign========================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec;
	STD_VECTOR std_vec;
	srand(time(NULL));
	init_global();
	std::cout << "range(1) ";
	measure_handler(ft_vec, std_vec, &range_assign_speed_test, &range_assign_speed_test);
	assign_vector_test(true);
	std::cout << std::endl;
	std::cout << "fill(2) ";
	measure_handler(ft_vec, std_vec, &fill_assign_speed_test, &fill_assign_speed_test);
	assign_vector_test(false);
	return 0;
}