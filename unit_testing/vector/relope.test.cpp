#include "vector_test.hpp"

int
start()
{
	CONTAINER::vector<TP> v(1, 4);
	CONTAINER::vector<TP> v2(4, 1);

	CONTAINER::vector<TP> v3(3, 1);
	CONTAINER::vector<TP> v4(3, 1);

	std::cout << "test [" << x++ << "]" << std::endl;
	
	std::cout << "test [" << x++ << "]" << std::endl;
	(v > v2)  ? std::cout << ">  Relationnal operator success" :
				std::cout << "> Relationnal operator fails";
	std::cout << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	(v < v2)  ? std::cout << "<  Relationnal operator success" :
				std::cout << "< Relationnal operator fails";
	std::cout << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	(v == v2) ?	std::cout << "== Relationnal operator success" :
				std::cout << "== Relationnal operator fails";
	std::cout << "test [" << x++ << "]" << std::endl;
	(v3 == v4) ?	std::cout << "== Relationnal operator success" :
				std::cout << "== Relationnal operator fails";
	std::cout << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	(v != v2) ? std::cout << "!= Relationnal operator success" :
				std::cout << "!= Relationnal operator fails";
	std::cout << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	(v <= v2) ? std::cout << "<= Relationnal operator success" :
				std::cout << "<= Relationnal operator fails";
	std::cout << std::endl;
	std::cout << "test [" << x++ << "]" << std::endl;
	(v >= v2) ? std::cout << ">= Relationnal operator success" :
				std::cout << ">= Relationnal operator fails";
	std::cout << std::endl;
	return 0;
}