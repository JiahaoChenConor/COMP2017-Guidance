#!/bin/bash

gcc -Wall -std=c11 q3.c -o q3.out


for test in *.input; do
    echo "ONE TEST START"
    ./q3.out < $test
    echo "ONE TEST END"
done

