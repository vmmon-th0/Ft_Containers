#!/bin/bash

cat benchmarking_intro
echo
echo

echo "STACK BM"
echo -n "ft::stack<> "
clang++ -std=c++98 -Wall -Wextra -Werror stack.test.cpp -D CONTAINER=ft && ./a.out
echo -n "std::stack<> "
clang++ -std=c++98 -Wall -Wextra -Werror stack.test.cpp -D CONTAINER=std && ./a.out
echo

echo "VECTOR BM"
echo -n "ft::vector<> "
clang++ -std=c++98 -Wall -Wextra -Werror vector.test.cpp -D CONTAINER=ft && ./a.out
echo -n "std::vector<> "
clang++ -std=c++98 -Wall -Wextra -Werror vector.test.cpp -D CONTAINER=std && ./a.out
echo

echo "MAP BM"
echo -n "ft::map<> "
clang++ -std=c++98 -Wall -Wextra -Werror map.test.cpp -D CONTAINER=ft && ./a.out
echo -n "std::map<> "
clang++ -std=c++98 -Wall -Wextra -Werror map.test.cpp -D CONTAINER=std && ./a.out
echo

echo "SET BM"
echo -n "ft::set<> "
clang++ -std=c++98 -Wall -Wextra -Werror set.test.cpp -D CONTAINER=ft && ./a.out
echo -n "std::stack<> "
clang++ -std=c++98 -Wall -Wextra -Werror set.test.cpp -D CONTAINER=std && ./a.out
echo

rm -f a.out