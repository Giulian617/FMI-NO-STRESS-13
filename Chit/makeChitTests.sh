#! /bin/bash
./gen_corect -max-m "15" -max-n "10" -min-m "2" -min-n "3" "ETWEF DWS" -small-cycles "true" > ./tests/chit_0.in
./sol_Mity_0 < ./tests/chit_0.in > ./tests/chit_0.out

./gen_corect -max-m "15" -max-n "10" -min-m "2" -min-n "3" "SDGERF EW" -small-cycles "true" > ./tests/chit_1.in
./sol_Mity_0 < ./tests/chit_1.in > ./tests/chit_1.out

./gen_corect -max-m "15" -max-n "10" -min-m "2" -min-n "3" "ssdfuecub" -small-cycles "false" > ./tests/chit_2.in
./sol_Mity_0 < ./tests/chit_2.in > ./tests/chit_2.out

./gen_corect -max-m "3000" -max-n "5" -min-m "1000" -min-n "3" "afeafesfsrhgar" -small-cycles "false" > ./tests/chit_3.in
./sol_Mity_0 < ./tests/chit_3.in > ./tests/chit_3.out

./gen_corect -max-m "100000" -max-n "5" -min-m "50000" -min-n "3" "ETWEF DWS" -small-cycles "false" > ./tests/chit_4.in
./sol_Mity_0 < ./tests/chit_4.in > ./tests/chit_4.out

./gen_corect -max-m "5" -max-n "100000" -min-m "1" -min-n "10000" "gshgraee" -small-cycles "true" > ./tests/chit_5.in
./sol_Mity_0 < ./tests/chit_5.in > ./tests/chit_5.out

./gen_corect -max-m "5" -max-n "100000" -min-m "1" -min-n "10000" "rgWRGEG4WRGR" -small-cycles "true" > ./tests/chit_6.in
./sol_Mity_0 < ./tests/chit_6.in > ./tests/chit_6.out

./gen_corect -max-m "5" -max-n "100000" -min-m "1" -min-n "10000" "Gewfg" -small-cycles "true" > ./tests/chit_7.in
./sol_Mity_0 < ./tests/chit_7.in > ./tests/chit_7.out

./gen_corect -max-m "100000" -max-n "100000" -min-m "100000" -min-n "100000" "gfaenfdijafvybe" -small-cycles "true" > ./tests/chit_8.in
./sol_Mity_0 < ./tests/chit_8.in > ./tests/chit_8.out

./gen_corect -max-m "100000" -max-n "100000" -min-m "100000" -min-n "100000" "ijdebuhdjadafhaeghrn" -small-cycles "false" > ./tests/chit_9.in
./sol_Mity_0 < ./tests/chit_9.in > ./tests/chit_9.out

