#!/bin/bash

cat benchmarking

clang++ -std=c++98 -Wall -Wextra -Werror main.cpp -D CONTAINER=ft
clang++ -std=c++98 -Wall -Wextra -Werror main.cpp -D CONTAINER=std