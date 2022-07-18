#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v;
	v.insert(v.begin(), 10, 1);
    printContent(v);
    v.reserve(20);
    v.insert(v.begin(), 2, 2);
    printContent(v);
    v.insert(v.end(), 1, 3);
    printContent(v);
    v.insert(v.end(), 2, 3);
    printContent(v);
    v.insert(v.end() - 1, 5);
	printContent(v);
	return 0;
}