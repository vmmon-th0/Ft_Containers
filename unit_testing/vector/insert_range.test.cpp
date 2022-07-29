#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;

	STD_VECTOR v2;
	STD_VECTOR v3;
	STD_VECTOR v4;
	for (int i = 0; i < 30; ++i)
	{
		if (i < 10)
		{
			v2.push_back(i);
		}
		else if (i >= 10 && i < 20)
		{
			v3.push_back(i);
		}
		else
		{
			v4.push_back(i);
		}
	}
	v.insert(v.begin(), v2.begin(), v2.end());
	printContent(v);
	v.reserve(50);
	v.insert(v.begin(), v3.begin(), v3.end() - 7);
	printContent(v);
	v.insert(v.end(), v3.begin() + 1, v3.begin() + 2);
	printContent(v);
	v.insert(v.end() - 1, v4.begin(), v4.end());
	printContent(v);
	v.insert(v.end() - 1, v4.begin(), v4.begin() + 1);
	printContent(v);
	return 0;
}