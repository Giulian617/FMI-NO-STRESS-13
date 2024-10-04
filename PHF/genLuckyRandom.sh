#! /bin/bash
./generator_random -N 1000000 -Q 100000 4 > ./tests/test_200.in
./phf < ./tests/test_200.in > ./tests/test_200.out

./generator_random -N 1000000 -Q 100000 18 > ./tests/test_201.in
./phf < ./tests/test_201.in > ./tests/test_201.out

./generator_random -N 1000000 -Q 100000 26 > ./tests/test_202.in
./phf < ./tests/test_202.in > ./tests/test_202.out

./generator_random -N 1000000 -Q 100000 232 > ./tests/test_203.in
./phf < ./tests/test_203.in > ./tests/test_203.out

./generator_random -N 1000000 -Q 100000 307 > ./tests/test_204.in
./phf < ./tests/test_204.in > ./tests/test_204.out
