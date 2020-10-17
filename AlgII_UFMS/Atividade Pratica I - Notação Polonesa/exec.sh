#! /usr/bin/env bash

gcc -ansi -Wall -pedantic main.c -o main && ./main $1 && rm -rf $1