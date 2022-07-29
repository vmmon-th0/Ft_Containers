#include "vector_test.hpp"

int
start()
{
	STD_VECTOR	v;
	STD_SET		s;
	STD_MAP		m;

	for (int i = 0; i < 1000; ++i)
	{
		v.push_back(i);
		s.insert(i);
		m.insert(std::make_pair(i, i));
	}
	CONTAINER::vector<TP>	v1(v.begin(), v.end());
	printContent(v1);
	CONTAINER::vector<TP>	v2(s.begin(), s.end());
	printContent(v2);
	CONTAINER::vector<TP>	v3(v.begin() + 1, v.end() - 1);
	printContent(v3);
	return 0;
}