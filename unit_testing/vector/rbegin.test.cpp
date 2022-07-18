#include "vector_test.hpp"

int
start()
{
    std::cout << "test [" << x++ << "]" << std::endl;
	CONTAINER::vector<TP>	v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
    std::cout << *v.rbegin() << std::endl;
    std::cout << "test [" << x++ << "]" << std::endl;
    CONTAINER::vector<TP>::reverse_iterator rit= v.rbegin();
    std::cout << *rit << std::endl;
    std::cout << "test [" << x++ << "]" << std::endl;
    CONTAINER::vector<TP>::const_reverse_iterator rit2 = v.rbegin();
     std::cout << *rit2 << std::endl;
    return 0;
}