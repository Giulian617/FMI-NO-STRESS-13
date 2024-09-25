#! /bin/bash
./gen_random -max-m "15" -max-n "10" -min-m "2" -min-n "3" "ETWEF DWS" -small-cycles "true" > ./tests/rnd_10.in
./sol_Mity_0 < ./tests/rnd_10.in > ./tests/rnd_10.out

./gen_random -max-m "15" -max-n "10" -min-m "2" -min-n "3" "SDGERF EW" -small-cycles "true" > ./tests/rnd_11.in
./sol_Mity_0 < ./tests/rnd_11.in > ./tests/rnd_11.out

./gen_random -max-m "15" -max-n "10" -min-m "2" -min-n "3" "ssdfuecub" -small-cycles "false" > ./tests/rnd_12.in
./sol_Mity_0 < ./tests/rnd_12.in > ./tests/rnd_12.out

./gen_random -max-m "3000" -max-n "5" -min-m "1000" -min-n "3" "afeafesfsrhgar" -small-cycles "false" > ./tests/rnd_13.in
./sol_Mity_0 < ./tests/rnd_13.in > ./tests/rnd_13.out

./gen_random -max-m "100000" -max-n "5" -min-m "50000" -min-n "3" "ETWEF DWS" -small-cycles "false" > ./tests/rnd_14.in
./sol_Mity_0 < ./tests/rnd_14.in > ./tests/rnd_14.out

./gen_random -max-m "5" -max-n "100000" -min-m "1" -min-n "10000" "gshgraee" -small-cycles "true" > ./tests/rnd_15.in
./sol_Mity_0 < ./tests/rnd_15.in > ./tests/rnd_15.out

./gen_random -max-m "5" -max-n "100000" -min-m "1" -min-n "10000" "rgWRGEG4WRGR" -small-cycles "true" > ./tests/rnd_16.in
./sol_Mity_0 < ./tests/rnd_16.in > ./tests/rnd_16.out

./gen_random -max-m "5" -max-n "100000" -min-m "1" -min-n "10000" "Gewfg" -small-cycles "true" > ./tests/rnd_17.in
./sol_Mity_0 < ./tests/rnd_17.in > ./tests/rnd_17.out

./gen_random -max-m "100000" -max-n "100000" -min-m "100000" -min-n "100000" "gfaenfdijafvybe" -small-cycles "true" > ./tests/rnd_18.in
./sol_Mity_0 < ./tests/rnd_18.in > ./tests/rnd_18.out

./gen_random -max-m "100000" -max-n "100000" -min-m "100000" -min-n "100000" "ijdebuhdjadafhaeghrn" -small-cycles "false" > ./tests/rnd_19.in
./sol_Mity_0 < ./tests/rnd_19.in > ./tests/rnd_19.out

