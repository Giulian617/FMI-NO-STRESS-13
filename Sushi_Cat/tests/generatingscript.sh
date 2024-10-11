#!/bin/bash

executable="bin/generator"

needs_recompile=false

# Check if the executable exists
if [[ ! -f "$executable" ]]; then
    needs_recompile=true
fi

# Check specific source files
for src_file in generator.cpp subtasks.cpp; do
    # If the source file is newer than the executable, mark for recompilation
    if [[ "$src_file" -nt "$executable" ]]; then
        needs_recompile=true
    fi
done

# Optionally check all header files (.hpp)
for header_file in generator.hpp; do
    # If the source file is newer than the executable, mark for recompilation
    if [[ "$header_file" -nt "$executable" ]]; then
        needs_recompile=true
    fi
done

# Final message if recompilation is required
if [[ "$needs_recompile" = true ]]; then
    echo "Generators are newer than the executable. Recompile needed."
    # Uncomment if you run on Unix
    g++ -std=c++17 -Wall `#-fsanitize=address,undefined,signed-integer-overflow` -O2 generator.cpp subtasks.cpp -o $executable

    # Exit the script if the compilation failed
    if [[ "$?" -ne 0 ]]; then
        exit 1
    fi
fi

if [[ "../src/Matteo.cpp" -nt "../src/bin/Matteo" ]]; then
    echo "Solution is newer than the executable. Recompile needed."
    # Uncomment if you run on Unix
    g++ -std=c++17 -Wall `#-fsanitize=address,undefined,signed-integer-overflow` -O2 ../src/Matteo.cpp -o ../src/bin/Matteo

    # Exit the script if the compilation failed
    if [[ "$?" -ne 0 ]]; then
        exit 1
    fi
fi

echo -n "Enter subtask number: "
read subtask
echo -n "Enter how many tests to generate: "
read no_tests

mkdir -p "Subtask_$subtask"

for test in $( seq 1 $no_tests ) 
do
    echo -ne "==== Test $test\n"
    echo "Generating test $test for subtask $subtask..."
    ./$executable $subtask > Subtask_$subtask/input_${subtask}_$test.in

    echo "Running solution on test $test..."
    ../src/bin/Matteo < Subtask_$subtask/input_${subtask}_$test.in > Subtask_$subtask/output_${subtask}_$test.out
done

