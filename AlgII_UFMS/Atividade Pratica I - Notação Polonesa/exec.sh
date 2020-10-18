#! /usr/bin/env bash

gcc -ansi -Wall -pedantic main.c -o main && ./main $1.in && cat $1.out && rm -rf $1.out && rm -rf main