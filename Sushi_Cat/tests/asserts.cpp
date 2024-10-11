#include <bits/stdc++.h>

using i64 = long long;

const int MAX_Q = 1e5;
const i64 MAX_X = 1e18;

void check_correctness(int subtask, int q, std::vector<i64> &x) {
    assert(1 <= q && q <= MAX_Q);
    for (auto xi : x)
        assert(1 <= xi && xi <= MAX_X);

    switch (subtask) {
        case 1:
            for (auto xi : x)
            assert(1 <= xi && xi <= 1e9);
            break;
    }
}

const int SUBTASKS = 2;
int main() {
    int number_of_tests[SUBTASKS + 1] = {0, 7, 3};
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
            int q;
            std::vector<i64> x;
            in >> q;
            x.resize(q);

            for (int i = 0; i < q; i++)
                in >> x[i];

            int y;
            while (in >> y)         // nu exista mai multe numere de atat in vector
                assert(false);

            // -------------------------------------------------------------------------
            //                                  ASSERTS
            // -------------------------------------------------------------------------
            check_correctness(subtask, q, x);

            in.close();
        }
    }

    std::cerr << "All tests are correct!\n";
    return 0;
}
