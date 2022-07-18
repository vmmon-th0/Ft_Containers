#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP>	v(1000, 1);
	printContent(v);
    return 0;
}