#include <ctime>
#include <deque>
#include <map>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include "set.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <iostream>
#include <numeric>
#include <sys/time.h>

/* Ajouter l'option dans makefile */
/* Ajouter valgrind output */
/* lower_bound, upper_bound */

#if !defined(CONTAINER)
#error unit testing require namespaces.
#endif

int
main()
{
	clock_t c;
	CONTAINER::stack<int>		st;
	CONTAINER::map<int, int>	m;
	CONTAINER::set<int>			se;
	CONTAINER::vector<int>		v(10000, 1);

	/*-stack-*/
	std::cout << "stack BM" << std::endl;
	c = std::clock();
	for (int i = 0; i < 100000; ++i)
	{
		st.push(i);
	}
	for (int i = 0; i < 100000; ++i)
	{
		st.pop();
	}
	std::cout << "time elapsed : " << (double)(std::clock() - c) / CLOCKS_PER_SEC << std::endl;
	std::cout << std::endl << std::endl;

	/*-vector-*/
	std::cout << "vector BM" << std::endl;
	c = std::clock();
	for (int i = 0; i < 100; i++)
	{
		volatile CONTAINER::vector<int> v(10000, 1);
	}
	for (int i = 0; i < 100; i++)
	{
		volatile CONTAINER::vector<int> y(v.begin(), v.end());
	}
	v.erase(v.begin(), v.end());
	v.insert(v.begin(), 10000, 1);
	v.clear();
	std::cout << "time elapsed : " << (double)(std::clock() - c) / CLOCKS_PER_SEC << std::endl;
	std::cout << std::endl << std::endl;

	/*-set-*/
	std::cout << "set BM" << std::endl;
	for (int i = 0; i < 10000; ++i)
	{
		se.insert(i);
	}
	c = std::clock();
	for (int i = 0; i < 100; i++)
	{
		volatile CONTAINER::set<int> v(se.begin(), se.end());
	}
	for (int i = 0; i < 100; i++)
	{
		volatile CONTAINER::set<int> y(se);
	}
	se.find(500);
	se.erase(se.begin(), se.end());
	for (int i = 0; i < 100000; ++i)
	{
		se.insert(i);
	}
	std::cout << "time elapsed : " << (double)(std::clock() - c) / CLOCKS_PER_SEC << std::endl;
	std::cout << std::endl << std::endl;
	return 0;
}
