#!/bin/bash

cat ../intro/vector_intro
echo
echo

COMPILE_ARGS=(	'fill_constructor_vector.cpp'	'range_constructor_vector.cpp'	'copy_constructor_vector.cpp'
				'assign_operator_vector.cpp'	'size_vector.cpp'				'max_size_vector.cpp'
				'resize_vector.cpp' 			'reserve_vector.cpp'			'assign_vector.cpp'				
				'push_back_vector.cpp'			'pop_back_vector.cpp'			'single_insert_vector.cpp'
				'fill_insert_vector.cpp'		'range_insert_vector.cpp'		'single_erase_vector.cpp'
				'range_erase_vector.cpp'		'swap_vector.cpp'				'clear_vector.cpp')

for arg in "${COMPILE_ARGS[@]}"; do
	clang++ "$arg" -Wall -Wextra -Werror "-std=c++98" && ./a.out
done

if [ -s log_file.log ]; then
	echo "You have differences to check in log_file.log"
else
	rm -f log_file.log
fi

rm -f a.out