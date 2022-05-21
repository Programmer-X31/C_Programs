#!/bin/sh

bold=$(tput bold)
normal=$(tput sgr0)

if [ $1 == "--help" ]; then
	echo "ex.sh - A utility script for compiling and running C programs" ;
	echo -e "Usage: \n\t${bold}run.sh <source_code_file.c> <executable.exe>${normal} " ;

elif [[ $1 == "--version" ]]; then
	echo "Version 0.0.1";

elif [[ $1 == "--math-lib" || $1 == "-m" ]]; then
	gcc -lm $1 -o $2 # Include Math Library
	./$2

else
	gcc $1 -o $2 # Normal Test Run
	./$2
fi
