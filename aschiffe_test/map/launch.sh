#!/bin/bash

cat ../intro/map_intro
echo
echo

COMPILE_ARGS=(		'assign_operator_map.cpp'	'clear_map.cpp'					'copy_constructor_map.cpp'
					'count_map.cpp'				'equal_range_map.cpp'			'find_map.cpp'
					'key_erase_map.cpp'			'lower_bound_map.cpp'			'upper_bound_map.cpp'
					'position_erase_map.cpp'	'range_constructor_map.cpp'		'range_erase_map.cpp'
					'range_insert_map.cpp'		'single_element_insert_map.cpp'	'swap_map.cpp')	

for arg in "${COMPILE_ARGS[@]}"; do
	clang++ "$arg" -Wall -Wextra -Werror "-std=c++98" && ./a.out
done

if [ -s log_file.log ]; then
	echo "You have differences to check in log_file.log"
else
	rm -f log_file.log
fi

rm -f a.out