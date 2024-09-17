#!/bin/bash

test_index_in=1
test_index_out=1

for test in Samples/*
do
    echo $test
    if [[ $test == *.in ]]
    then
        cp $test $test_index_in.in
        test_index_in=$((test_index_in+1))
    else 
        cp $test $test_index_out.out
        test_index_out=$((test_index_out+1))
    fi
done

for subtask in $( seq 1 6 ) 
do
    echo $subtask
    for test in Subtask_$subtask/* 
    do
        echo $test
        if [[ $test == *.in ]]
        then
            cp $test $test_index_in.in
            test_index_in=$((test_index_in+1))
        else 
            cp $test $test_index_out.out
            test_index_out=$((test_index_out+1))
        fi
    done
done

# Zip all the files
zip -r tests.zip *.in *.out .properties

# Remove all the files
rm *.in *.out
