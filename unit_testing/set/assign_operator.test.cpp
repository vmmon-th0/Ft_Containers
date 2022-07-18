#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP> s;
    for (int i = 0; i < 10; ++i)
	{
		s.insert(i);
	}
    CONTAINER::set<TP> s1;
	s1 = s;
    printContent(s1);
	for (int i = 0; i < 4; ++i)
	{
		s1.insert(i);
	}
	s = s1;
	printContent(s);
	std::cout << "test [" << x++ << "]" << std::endl;
    CONTAINER::set<TP> s2;
    CONTAINER::set<TP> s3;
    for (int i = 0; i < 10; ++i)
    {
        if (i < 5)
        {
			s2.insert(i);
        }
		else
		{
			s3.insert(i);
		}
    }
	CONTAINER::set<TP> s4;
	s4 = s2;
	s3 = s4;
	printContent(s4);
	printContent(s3);
    return 0;
}