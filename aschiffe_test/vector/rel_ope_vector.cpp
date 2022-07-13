#include "test_vector.hpp"

/*
	(1)	
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	(2)	
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	(3)	
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	(4)	
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	(5)	
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	(6)	
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
*/

static int test_count = 0;

FT_VECTOR	ft_test;
STD_VECTOR	std_test;

void
rel_ope_vector_test()
{
	FT_VECTOR ft_vec;
	STD_VECTOR std_vec;

	for (int i = 0; i < 100; ++i)
	{
		size_t k = rand() % 100;
		ft_vec.push_back(k);
		std_vec.push_back(k);
	}

	ft_vec == ft_test ? ft_vec.push_back(true) : ft_vec.push_back(false);
	ft_vec != ft_test ? ft_vec.push_back(true) : ft_vec.push_back(false);
	ft_vec < ft_test ? ft_vec.push_back(true) : ft_vec.push_back(false);
	ft_vec <= ft_test ? ft_vec.push_back(true) : ft_vec.push_back(false);
	ft_vec > ft_test ? ft_vec.push_back(true) : ft_vec.push_back(false);
	ft_vec >= ft_test ? ft_vec.push_back(true) : ft_vec.push_back(false);

	std_vec == std_test ? std_vec.push_back(true) : std_vec.push_back(false);
	std_vec != std_test ? std_vec.push_back(true) : std_vec.push_back(false);
	std_vec < std_test ? std_vec.push_back(true) : std_vec.push_back(false);
	std_vec <= std_test ? std_vec.push_back(true) : std_vec.push_back(false);
	std_vec > std_test ? std_vec.push_back(true) : std_vec.push_back(false);
	std_vec >= std_test ? std_vec.push_back(true) : std_vec.push_back(false);

	verify_content(ft_vec, std_vec, ++test_count);
}

template<typename ContainerType>
void
ft_rel_ope_speed_test(ContainerType& x)
{
    if (x == ft_test)
	{
	}
	if (x != ft_test)
	{
	}
	if (x < ft_test)
	{
	}
	if (x <= ft_test)
	{
	}
	if (x > ft_test)
	{
	}
	if (x >= ft_test)
	{
	}
}

template<typename ContainerType>
void
std_rel_ope_speed_test(ContainerType& x)
{
	if (x == std_test)
	{
	}
	if (x != std_test)
	{
	}
	if (x < std_test)
	{
	}
	if (x <= std_test)
	{
	}
	if (x > std_test)
	{
	}
	if (x >= std_test)
	{
	}
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
	std::cout << "==============================rel-ope=======================================" << std::endl
																								<< std::endl;
}

int
start()
{
	intro();
	FT_VECTOR ft_vec(100, 1);
	STD_VECTOR std_vec(100, 1);
	srand(time(NULL));
	init_global();
	measure_handler(ft_vec, std_vec, &ft_rel_ope_speed_test, &std_rel_ope_speed_test);
	rel_ope_vector_test();
	return 0;
}