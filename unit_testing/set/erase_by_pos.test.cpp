#include "set_test.hpp"

int
start()
{
	CONTAINER::set<TP>	s;
    for (int i = 0; i < 10; ++i)
    {
        s.insert(i);
    }
    s.erase(s.begin());
    printContent(s);
    s.erase(--(s.end()));
    printContent(s);
    return 0;
}