#! /bin/bash
./genRand -delta "5" -max-K "0" -max-N "10" -max-W "10" -min-K "0" -min-N "2" -min-W "1" "ladfnfsd" > ./tests/test_0.in
./sol_Mity < ./tests/test_0.in > ./tests/test_0.out

./genRand -delta "10" -max-K "0" -max-N "10" -max-W "10" -min-K "0" -min-N "5" -min-W "1" "fds" > ./tests/test_1.in
./sol_Mity < ./tests/test_1.in > ./tests/test_1.out

./genRand -delta "30" -max-K "0" -max-N "50" -max-W "10" -min-K "0" -min-N "5" -min-W "1" "daege" > ./tests/test_2.in
./sol_Mity < ./tests/test_2.in > ./tests/test_2.out

./genRand -delta "20" -max-K "0" -max-N "100" -max-W "10" -min-K "0" -min-N "20" -min-W "1" "fsd" > ./tests/test_3.in
./sol_Mity < ./tests/test_3.in > ./tests/test_3.out

./genRand -delta "100" -max-K "0" -max-N "100" -max-W "10" -min-K "0" -min-N "100" -min-W "1" "g" > ./tests/test_4.in
./sol_Mity < ./tests/test_4.in > ./tests/test_4.out

./genRand -delta "5" -max-K "1" -max-N "10" -max-W "10" -min-K "1" -min-N "5" -min-W "1" "sG" > ./tests/test_5.in
./sol_Mity < ./tests/test_5.in > ./tests/test_5.out

./genRand -delta "10" -max-K "1" -max-N "10" -max-W "10" -min-K "1" -min-N "5" -min-W "1" "sdg" > ./tests/test_6.in
./sol_Mity < ./tests/test_6.in > ./tests/test_6.out

./genRand -delta "30" -max-K "1" -max-N "50" -max-W "10" -min-K "1" -min-N "5" -min-W "1" "sgfs" > ./tests/test_7.in
./sol_Mity < ./tests/test_7.in > ./tests/test_7.out

./genRand -delta "20" -max-K "1" -max-N "100" -max-W "10" -min-K "1" -min-N "20" -min-W "1" "df" > ./tests/test_8.in
./sol_Mity < ./tests/test_8.in > ./tests/test_8.out

./genRand -delta "100" -max-K "1" -max-N "100" -max-W "10" -min-K "1" -min-N "100" -min-W "1" "hs" > ./tests/test_9.in
./sol_Mity < ./tests/test_9.in > ./tests/test_9.out

./genRand -delta "1" -max-K "100" -max-N "10" -max-W "10" -min-K "0" -min-N "5" -min-W "1" "dgsd" > ./tests/test_10.in
./sol_Mity < ./tests/test_10.in > ./tests/test_10.out

./genRand -delta "1" -max-K "200" -max-N "10" -max-W "10" -min-K "100" -min-N "5" -min-W "1" "gsfh" > ./tests/test_11.in
./sol_Mity < ./tests/test_11.in > ./tests/test_11.out

./genRand -delta "1" -max-K "1000" -max-N "50" -max-W "10" -min-K "1000" -min-N "5" -min-W "1" "sgh" > ./tests/test_12.in
./sol_Mity < ./tests/test_12.in > ./tests/test_12.out

./genRand -delta "1" -max-K "3000000" -max-N "100" -max-W "10" -min-K "20000" -min-N "20" -min-W "1" "hrg" > ./tests/test_13.in
./sol_Mity < ./tests/test_13.in > ./tests/test_13.out

./genRand -delta "1" -max-K "100000000000000" -max-N "100" -max-W "10" -min-K "3000000" -min-N "100" -min-W "1" "sG" > ./tests/test_14.in
./sol_Mity < ./tests/test_14.in > ./tests/test_14.out

./genRand -delta "100" -max-K "1000" -max-N "100" -max-W "10" -min-K "1000" -min-N "100" -min-W "1" "dv" > ./tests/test_15.in
./sol_Mity < ./tests/test_15.in > ./tests/test_15.out

./genRand -delta "100" -max-K "5000" -max-N "100" -max-W "10" -min-K "5000" -min-N "100" -min-W "1" "resefcve" > ./tests/test_16.in
./sol_Mity < ./tests/test_16.in > ./tests/test_16.out

./genRand -delta "100" -max-K "10000" -max-N "100" -max-W "10" -min-K "10000" -min-N "100" -min-W "1" "afe" > ./tests/test_17.in
./sol_Mity < ./tests/test_17.in > ./tests/test_17.out

./genRand -delta "100" -max-K "20000" -max-N "100" -max-W "10" -min-K "10000" -min-N "100" -min-W "1" "f" > ./tests/test_18.in
./sol_Mity < ./tests/test_18.in > ./tests/test_18.out

./genRand -delta "100" -max-K "20000" -max-N "100" -max-W "10" -min-K "10000" -min-N "100" -min-W "1" "err" > ./tests/test_19.in
./sol_Mity < ./tests/test_19.in > ./tests/test_19.out

./genRand -delta "100" -max-K "20000" -max-N "100" -max-W "10" -min-K "10000" -min-N "100" -min-W "1" "grh" > ./tests/test_20.in
./sol_Mity < ./tests/test_20.in > ./tests/test_20.out

./genRand -delta "100" -max-K "20000" -max-N "100" -max-W "10" -min-K "10000" -min-N "100" -min-W "1" "se" > ./tests/test_21.in
./sol_Mity < ./tests/test_21.in > ./tests/test_21.out

./genRand -delta "100" -max-K "100000000000000" -max-N "100" -max-W "10" -min-K "100000000000" -min-N "100" -min-W "1" "ef" > ./tests/test_22.in
./sol_Mity < ./tests/test_22.in > ./tests/test_22.out

./genRand -delta "100" -max-K "100000000000000" -max-N "100" -max-W "10" -min-K "100000000000" -min-N "100" -min-W "1" "f" > ./tests/test_23.in
./sol_Mity < ./tests/test_23.in > ./tests/test_23.out

./genRand -delta "100" -max-K "100000000000000" -max-N "100" -max-W "10" -min-K "100000000000" -min-N "100" -min-W "1" "efaefqwfef" > ./tests/test_24.in
./sol_Mity < ./tests/test_24.in > ./tests/test_24.out

./genRand -delta "100" -max-K "100000000000000" -max-N "100" -max-W "10" -min-K "100000000000" -min-N "100" -min-W "1" "daw" > ./tests/test_25.in
./sol_Mity < ./tests/test_25.in > ./tests/test_25.out

./genRand -delta "100" -max-K "100000000000000" -max-N "100" -max-W "10" -min-K "100000000000" -min-N "100" -min-W "1" "fgeagg" > ./tests/test_26.in
./sol_Mity < ./tests/test_26.in > ./tests/test_26.out

./genRand -delta "100" -max-K "100000000000000" -max-N "100" -max-W "10" -min-K "100000000000" -min-N "100" -min-W "1" "fea" > ./tests/test_27.in
./sol_Mity < ./tests/test_27.in > ./tests/test_27.out

./genRand -delta "100" -max-K "100000000000000" -max-N "100" -max-W "10" -min-K "100000000000" -min-N "100" -min-W "1" "fea" > ./tests/test_28.in
./sol_Mity < ./tests/test_28.in > ./tests/test_28.out

