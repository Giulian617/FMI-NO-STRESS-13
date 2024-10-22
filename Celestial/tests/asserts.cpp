#include <bits/stdc++.h>
#include "generator.hpp"

void check_correctness(TestData &data) {
    assert(1 <= data.N && data.N <= MAX_N);
    assert(1 <= data.L && data.L <= MAX_L);
    for (int i = 0; i < data.N; i++) {
        assert(0 <= data.stars[i].x && data.stars[i].x <= MAX_POINT);
        assert(0 <= data.stars[i].y && data.stars[i].y <= MAX_POINT);
        assert(0 <= data.stars[i].z && data.stars[i].z <= MAX_POINT);
        assert(!(data.stars[i].x == 0 && data.stars[i].y == 0 && data.stars[i].z == 0));
    }

    for (int i = 0; i < data.L; i++) {
        assert(0 <= data.lanterns[i].x && data.lanterns[i].x <= MAX_POINT);
        assert(0 <= data.lanterns[i].y && data.lanterns[i].y <= MAX_POINT);
        assert(0 <= data.lanterns[i].z && data.lanterns[i].z <= MAX_POINT);
        assert(0 <= data.lanterns[i].phi && data.lanterns[i].phi <= MAX_PHI);
        assert(!(data.lanterns[i].x == 0 && data.lanterns[i].y == 0 && data.lanterns[i].z == 0));
    }
}

const int SUBTASKS = 1;
int main() {
    int number_of_tests[SUBTASKS + 1] = {0, 30};
    std::ifstream in;

    for (int subtask = 1; subtask <= SUBTASKS; subtask++) {
        std::string filename = "Subtask_", currdir;
        filename += std::to_string(subtask);
        filename += "/";

        currdir = filename;
        for (int i = 1; i <= number_of_tests[subtask]; i++) {
            // -------------------------------------------------------------------------
            //                               FILE OPENING
            // -------------------------------------------------------------------------
            filename = currdir;
            std::string input = filename + "input_" + std::to_string(subtask) + "_";
            input += std::to_string(i) + ".in";

            std::cerr << input << '\n';
            in.open(input.c_str());

            // -------------------------------------------------------------------------
            //                               FILE READING
            // -------------------------------------------------------------------------
            TestData data;
            in >> data.N;
            data.stars.resize(data.N);
            for (int i = 0; i < data.N; i++)
                in >> data.stars[i].x >> data.stars[i].y >> data.stars[i].z;

            in >> data.L;
            data.lanterns.resize(data.N);
            for (int i = 0; i < data.L; i++)
                in >> data.lanterns[i].x >> data.lanterns[i].y >> data.lanterns[i].z >> data.lanterns[i].phi;
            int x;
            while (in >> x)         // nu exista mai multe numere de atat in vector
                assert(false);

            // -------------------------------------------------------------------------
            //                                  ASSERTS
            // -------------------------------------------------------------------------
            check_correctness(data);

            in.close();
        }
    }

    std::cerr << "All tests are correct!\n";
    return 0;
}
