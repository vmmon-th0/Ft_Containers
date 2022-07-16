#include "../general.hpp"

/* The volatile keyword is intended to prevent the compiler from applying any optimizations on objects that can change in ways that cannot be determined by the compiler. Objects declared as volatile are omitted from optimization because their values can be changed by code outside the scope of current code at any time. */

/*-copy constructor-*/

void
copy_constructor_vector_test()
{
    clock_t c;
	SAMPLE_VEC samples;
	CONTAINER::vector<TP> x(100000, 1);
	for (int i = 0; i < COPY_SAMPLES_NB; ++i)
	{
		c = std::clock();
		volatile CONTAINER::vector<TP> y(x);
		samples.push_back((double)(std::clock() - c) / CLOCKS_PER_SEC);
	}
	std::cout << std::accumulate(samples.begin(), samples.end(), 0.) / COPY_SAMPLES_NB << std::endl;
}

/*-range constructor-*/

void
range_constructor_vector_test()
{
    clock_t c;
	SAMPLE_VEC samples;
	CONTAINER::vector<TP> x(10000, 1);
	for (int i = 0; i < RANGE_SAMPLES_NB; ++i)
	{
		c = std::clock();
		volatile CONTAINER::vector<TP> y(x.begin(), x.end());
		samples.push_back((double)(std::clock() - c) / CLOCKS_PER_SEC);
	}
	std::cout << std::accumulate(samples.begin(), samples.end(), 0.) / RANGE_SAMPLES_NB << std::endl;
}

/*-fill constructor-*/

void
fill_constructor_vector_test()
{
	clock_t c;
	SAMPLE_VEC samples;
	CONTAINER::vector<TP> x(100000, 1);
	for (int i = 0; i < FILL_SAMPLES_NB; ++i)
	{
		c = std::clock();
		volatile CONTAINER::vector<TP> y(10000, i);
		samples.push_back((double)(std::clock() - c) / CLOCKS_PER_SEC);
	}
	std::cout << std::accumulate(samples.begin(), samples.end(), 0.) / FILL_SAMPLES_NB << std::endl;
}

/*-insert-*/

void
single_insert_vector_test()
{
	clock_t c;
	SAMPLE_VEC samples;
	CONTAINER::vector<TP> x;
	for (int i = 0; i < SINGLE_INSERT_NB; ++i)
	{
		c = std::clock();
		x.insert(x.begin(), 1);
		samples.push_back((double)(std::clock() - c) / CLOCKS_PER_SEC);
	}
	std::cout << std::accumulate(samples.begin(), samples.end(), 0.) / SINGLE_INSERT_NB << std::endl;
}

void
fill_insert_vector_test()
{
	clock_t c;
	SAMPLE_VEC samples;
	CONTAINER::vector<TP> x;
	for (int i = 0; i < FILL_INSERT_NB; ++i)
	{
		c = std::clock();
		x.insert(x.begin(), 100, 1);
		samples.push_back((double)(std::clock() - c) / CLOCKS_PER_SEC);
	}
	std::cout << std::accumulate(samples.begin(), samples.end(), 0.) / FILL_INSERT_NB << std::endl;
}

void
range_insert_vector_test()
{
	clock_t c;
	SAMPLE_VEC samples;
	CONTAINER::vector<TP> x;
	CONTAINER::vector<TP> y(100, 1);
	for (int i = 0; i < RANGE_INSERT_NB; ++i)
	{
		c = std::clock();
		x.insert(x.begin(), y.begin(), y.end());
		samples.push_back((double)(std::clock() - c) / CLOCKS_PER_SEC);
	}
	std::cout << std::accumulate(samples.begin(), samples.end(), 0.) / RANGE_INSERT_NB << std::endl;
}

void
single_erase_vector_test()
{
	clock_t c;
	SAMPLE_VEC samples;
	CONTAINER::vector<TP> x(1000, 1);
	for (int i = 0; i < SINGLE_ERASE_NB; ++i)
	{
		c = std::clock();
		x.erase(x.begin());
		samples.push_back((double)(std::clock() - c) / CLOCKS_PER_SEC);
	}
	std::cout << std::accumulate(samples.begin(), samples.end(), 0.) / SINGLE_ERASE_NB << std::endl;
}

void
range_erase_vector_test()
{
	clock_t c;
	SAMPLE_VEC samples;
	for (int i = 0; i < RANGE_ERASE_NB; ++i)
	{
		CONTAINER::vector<TP> x(10000, 1);
		c = std::clock();
		x.erase(x.begin(), x.end());
		samples.push_back((double)(std::clock() - c) / CLOCKS_PER_SEC);
	}
	std::cout << std::accumulate(samples.begin(), samples.end(), 0.) / RANGE_ERASE_NB << std::endl;
}

/*-mixed operations-*/

void
mixed_operations_vector_test()
{
	clock_t c;
	c = std::clock();
	CONTAINER::vector<TP> x(1000, 1);
	for (int i = 0; i < 10; ++i)
	{
		x.erase(x.begin());
	}
	x.insert(x.begin(), 1000, 1);
	CONTAINER::vector<TP> y = x;
	x.clear();
	y.clear();
	std::cout << (double)(std::clock() - c) / CLOCKS_PER_SEC << std::endl;
}

int
start()
{
    // std::cout << "copy constructor" << std::endl;
    // copy_constructor_vector_test();
	// std::cout << "range constructor" << std::endl;
	// range_constructor_vector_test();
	// std::cout << "fill constructor" << std::endl;
	// fill_constructor_vector_test();
	// std::cout << "single insert" << std::endl;
	// single_insert_vector_test();
	// std::cout << "fill insert" << std::endl;
	// fill_insert_vector_test();
	// std::cout << "range insert" << std::endl;
	// range_insert_vector_test();
	// std::cout << "single erase" << std::endl;
	// single_erase_vector_test();
	std::cout << "range erase" << std::endl;
	range_erase_vector_test();
	// std::cout << "mixed operations" << std::endl;
	// mixed_operations_vector_test();
	return 0;
}