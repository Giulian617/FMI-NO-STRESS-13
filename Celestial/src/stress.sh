#!/bin/bash

optimized="./bin/Marius"
brute="./bin/Stefan"
generator="./bin/generator"

current_test=1
while true; do
    $generator > input.txt
    $brute < input.txt > out1.txt
    $optimized < input.txt > out2.txt
    
    echo -ne "Test $current_test: \r"
    current_test=$((current_test + 1))

    if diff -w out1.txt out2.txt; then
        echo -ne "Test $current_test: OK\r"
    else
        echo "FAIL"
        exit 1
    fi
done

