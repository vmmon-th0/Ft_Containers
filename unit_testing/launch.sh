#!/bin/bash

# How catch valgrind ? If we have valgrind errors, we store it in files
# How catch fsanitize ? If we have sanitize errors, we store it in files

RED='\033[0;31m'		# Red
GREEN='\033[0;32m'		# Green
YELLLOW='\033[0;33m'	# Yellow

RESET='\033[0m'			# Text Reset

ARGS=("$@")
NB=$#

function launchtest()
{
	echo
	echo "---------------------------------------------"
	echo
	for x in *.cpp; do
		clang++ -Wall -Wextra -Werror -std=c++98 $x -D CONTAINER=ft -o x >& z
		clang++ -Wall -Wextra -Werror -std=c++98 $x -D CONTAINER=std -o y

		echo -n $x " "

		for ((i = 0; i < 32 - (${#x} + 7); ++i)); do
			echo -n " "
		done

		# Capturing shell message & redirect stdout stderr
		{ ./x; } > /dev/null 2>&1

		# Announce exit error
		EXIT_CODE=$?
		if [[ $EXIT_CODE != 0 ]]; then
			if [[ $EXIT_CODE == 139 ]];	then
				echo -e $RED "segfault error" $RESET
			elif [[ $EXIT_CODE == 134 ]]; then
				echo -e $RED "invalid free" $RESET
			fi
			continue
		fi

		# Checking for compile errors
		if [[ -z z ]]; then
			echo -e $RED "compile error" $RESET
		else
			diff <(./x) <(./y) > tmp
			if [[ -z tmp ]]; then
				diff <(./x) <(./y) >> stack_diff
			else
				echo -e $GREEN "identical output" $RESET
			fi
			rm -f tmp
		fi
	done
		rm -f x y z
	cd ..
}

function stack()
{
	cat intro/stack_intro
	cd stack
	launchtest
}

function vector()
{
	cat intro/vector_intro
	cd vector
	launchtest
}

function map()
{
	cat intro/map_intro
	cd map
	launchtest
}

function set()
{
	cat intro/set_intro
	cd set
	launchtest
}

function main()
{
	${TEST}
	if [[ -z ${ARGS[0]} ]]; then
		stack
		vector
		map
		set
	else
		for ((i = 0 ; i < $NB ; i++)); do
			${ARGS[0]}
		done
	fi
}

main