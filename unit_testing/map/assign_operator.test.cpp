#include "map_test.hpp"

int
start()
{
	CONTAINER::map<TP1, TP2> v;
    for (int i = 0; i < 1000; ++i)
	{
		v.insert(CONTAINER::make_pair(i, i));
	}
    CONTAINER::map<TP1, TP2> v1;
	v1 = v;
    printContent(v1);
	for (CONTAINER::map<TP1, TP2>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		it->second *= 2;
	}
	v = v1;
	printContent(v);
	std::cout << "test [" << x++ << "]" << std::endl;
    CONTAINER::map<TP1, TP2> v2;
    CONTAINER::map<TP1, TP2> v3;
    for (int i = 0; i < 10; ++i)
    {
        if (i < 5)
        {
			v2.insert(CONTAINER::make_pair(i, i));
        }
		else
		{
			v3.insert(CONTAINER::make_pair(i, i));
		}
    }
	CONTAINER::map<TP1, TP2> v4;
	v4 = v2;
	v3 = v2;
	printContent(v4);
	printContent(v3);
    return 0;
}