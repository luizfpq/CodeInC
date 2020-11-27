#!/usr/bin/env bash
rm -rf trab1 &&\
rm -rf $1.out
gcc -ansi -Wall -pedantic trab1.c -o trab1 &&\
 ./trab1 $1.in &&\
  cat $1.out