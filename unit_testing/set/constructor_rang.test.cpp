#include "set_test.hpp"

int
start()
{
	STD_VECTOR           	v;
    STD_SET					s;
	STD_MAP					m;

    for (int i = 0; i < 1000; ++i)
	{
		v.push_back(i);
		s.insert(i);
		m.insert(std::make_pair(i, i));
	}
	CONTAINER::set<TP>	s1(v.begin(), v.end());
    printContent(s1);
    CONTAINER::set<TP>	s2(s.begin(), s.end());
	printContent(s2);
    CONTAINER::set<TP>	s3(v.begin() + 1, v.end() - 1);
	printContent(s3);
    return 0;
}