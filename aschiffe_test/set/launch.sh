#!/bin/bash

cat ../intro/set_intro
echo
echo

COMPILE_ARGS=(		'assign_operator_set.cpp'	'clear_set.cpp'					'copy_constructor_set.cpp'
					'count_set.cpp'				'equal_range_set.cpp'			'find_set.cpp'
					'key_erase_set.cpp'			'lower_bound_set.cpp'			'upper_bound_set.cpp'
					'position_erase_set.cpp'	'range_constructor_set.cpp'		'range_erase_set.cpp'
					'range_insert_set.cpp'		'single_element_insert_set.cpp'	'swap_set.cpp')	

for arg in "${COMPILE_ARGS[@]}"; do
	clang++ "$arg" -Wall -Wextra -Werror "-std=c++98" && ./a.out
done

if [ -s log_file.log ]; then
	echo "You have differences to check in log_file.log"
else
	rm -f log_file.log
fi

rm -f a.out