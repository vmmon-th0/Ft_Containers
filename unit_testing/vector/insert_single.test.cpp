#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v(10, 1);
	v.insert(v.begin(), 2);
	printContent(v);
	v.insert(v.end(), 3);
	printContent(v);
	v.insert(v.begin() + 1, 4);
	printContent(v);
	v.insert(v.end() - 1, 5);
	printContent(v);
	CONTAINER::vector<TP> v2;
	v2.insert(v2.begin(), 2);
	printContent(v2);
	v2.insert(v2.end(), 3);
	printContent(v2);
	v2.insert(v2.begin() + 1, 4);
	printContent(v2);
	v2.insert(v2.end() - 1, 5);
	printContent(v2);
	return 0;
}