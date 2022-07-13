#!/bin/bash

cat ../intro/stack_intro
echo
echo

COMPILE_ARGS=(		'empty_stack.cpp'	        'pop_stack.cpp'					'push_stack.cpp'
					'rel_ope_stack.cpp'			'size_stack.cpp'			    'top_stack.cpp')	

for arg in "${COMPILE_ARGS[@]}"; do
	clang++ "$arg" -Wall -Wextra -Werror "-std=c++98" && ./a.out
done

if [ -s log_file.log ]; then
	echo "You have differences to check in log_file.log"
else
	rm -f log_file.log
fi

rm -f a.out