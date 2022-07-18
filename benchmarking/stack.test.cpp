#include "general.hpp"

int
start()
{
    /*-stack-*/
	clock_t c;
	CONTAINER::stack<int>	st;
	c = std::clock();
	for (int i = 0; i < 100000; ++i)
	{
		st.push(i);
	}
	for (int i = 0; i < 100000; ++i)
	{
		st.pop();
	}
	std::cout << "time elapsed : " << (double)(std::clock() - c) / CLOCKS_PER_SEC << "[s]" << std::endl;
}