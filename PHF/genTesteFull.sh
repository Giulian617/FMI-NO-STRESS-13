#! /bin/bash
./generator_all_combo -N 2 > ./tests/test_100.in
./phf < ./tests/test_100.in > ./tests/test_100.out

./generator_all_combo -N 3 > ./tests/test_101.in
./phf < ./tests/test_101.in > ./tests/test_101.out

./generator_all_combo -N 4 > ./tests/test_102.in
./phf < ./tests/test_102.in > ./tests/test_102.out

./generator_all_combo -N 5 > ./tests/test_103.in
./phf < ./tests/test_103.in > ./tests/test_103.out

./generator_all_combo -N 6 > ./tests/test_104.in
./phf < ./tests/test_104.in > ./tests/test_104.out

./generator_all_combo -N 7 > ./tests/test_105.in
./phf < ./tests/test_105.in > ./tests/test_105.out

./generator_all_combo -N 8 > ./tests/test_106.in
./phf < ./tests/test_106.in > ./tests/test_106.out

./generator_all_combo -N 9 > ./tests/test_107.in
./phf < ./tests/test_107.in > ./tests/test_107.out

./generator_all_combo -N 10 > ./tests/test_108.in
./phf < ./tests/test_108.in > ./tests/test_108.out
