#! /bin/bash
./genStar -max-K "0" -max-N "100" -max-W "10" -min-K "0" -min-N "100" -min-W "1" "gejfaeok" -root1 "true" > ./tests/test_100.in
./sol_Mity < ./tests/test_100.in > ./tests/test_100.out

./genStar -max-K "0" -max-N "100" -max-W "10" -min-K "0" -min-N "100" -min-W "1" "eafeaf" -root1 "false" > ./tests/test_101.in
./sol_Mity < ./tests/test_101.in > ./tests/test_101.out

./genStar -max-K "1" -max-N "100" -max-W "10" -min-K "1" -min-N "100" -min-W "1" "9yf9feg" -root1 "true" > ./tests/test_102.in
./sol_Mity < ./tests/test_102.in > ./tests/test_102.out

./genStar -max-K "1" -max-N "100" -max-W "10" -min-K "1" -min-N "100" -min-W "1" "sefuigeegr" -root1 "false" > ./tests/test_103.in
./sol_Mity < ./tests/test_103.in > ./tests/test_103.out

./genStar -max-K "20000" -max-N "100" -max-W "10" -min-K "10000" -min-N "100" -min-W "1" "jedishefeh" -root1 "true" > ./tests/test_104.in
./sol_Mity < ./tests/test_104.in > ./tests/test_104.out

./genStar -max-K "20000" -max-N "100" -max-W "10" -min-K "10000" -min-N "100" -min-W "1" "fheuds" -root1 "false" > ./tests/test_105.in
./sol_Mity < ./tests/test_105.in > ./tests/test_105.out

./genStar -max-K "1000000000000000000" -max-N "100" -max-W "10" -min-K "1000000000000" -min-N "100" -min-W "1" "shfeaed" -root1 "true" > ./tests/test_106.in
./sol_Mity < ./tests/test_106.in > ./tests/test_106.out

./genStar -max-K "1000000000000000000" -max-N "100" -max-W "10" -min-K "1000000000000" -min-N "100" -min-W "1" "sadawfawa" -root1 "false" > ./tests/test_107.in
./sol_Mity < ./tests/test_107.in > ./tests/test_107.out

