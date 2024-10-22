#!/bin/bash

optimized="./bin/Matteo"
generator="./bin/generator"

current_test=1
while true; do
    echo "Test $current_test: "
    $generator > input.txt
    echo "Generated input"
    $optimized < input.txt > out1.txt
    echo "Optimized version executed"
    # Get the time of the optimized version
    # time=$(time $optimized < input.txt > out1.txt 2>&1)
    # echo "Time of the optimized version: $time1"
    
    # If the return code is not 0, exit
    if [ $? -ne 0 ]; then
        echo "Error in the optimized version"
        exit 1
    fi

    echo -ne "Test $current_test: OK\r"
    current_test=$((current_test + 1))
done

