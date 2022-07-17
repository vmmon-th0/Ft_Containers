#include "stack_test.hpp"

int
start()
{
	CONTAINER::stack<TP> s;
    CONTAINER::stack<TP> s2;

    std::cout << "test [" << x++ << "]" << std::endl;
	s.push(10);
	s.push(5);

    s2.push(15);
	s2.push(10);

	(s > s2)  ? std::cout << ">  Relationnal operator success" :
				std::cout << "> Relationnal operator fails";
    std::cout << std::endl;
	(s < s2)  ? std::cout << "<  Relationnal operator success" :
                std::cout << "< Relationnal operator fails";
    std::cout << std::endl;
	(s == s2) ?	std::cout << "== Relationnal operator success" :
                std::cout << "== Relationnal operator fails";
    std::cout << std::endl;
	(s != s2) ? std::cout << "!= Relationnal operator success" :
                std::cout << "!= Relationnal operator fails";
    std::cout << std::endl;
	(s <= s2) ? std::cout << "<= Relationnal operator success" :
                std::cout << "<= Relationnal operator fails";
    std::cout << std::endl;
	(s >= s2) ? std::cout << ">= Relationnal operator success" :
                std::cout << ">= Relationnal operator fails";
	std::cout << std::endl;
	return 0;
}