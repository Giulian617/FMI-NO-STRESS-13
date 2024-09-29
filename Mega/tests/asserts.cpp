#include <bits/stdc++.h>

const int MAX_N = 2e5;
const int MAX_M = 2e5;
const int MAX_T = 1e9;

void check_correctness(int subtask, int n, int m, std::vector<int> &t) {
    assert(1 <= n && n <= MAX_N);
    assert(1 <= m && m <= MAX_M);

    for (auto ti : t)
        assert(1 <= ti && ti <= MAX_T);

    switch (subtask) {
        case 1:
            assert(m < n);
            break;

        case 2:
            assert(m == n);
            break;

        case 3:
            assert(n == 1);
            break;

        case 4:
            for (int i = 1; i < m; i++)
                assert(t[i] == t[i - 1]);
            break;

        case 5:
            assert(m <= 2000);
            break;
    }
}

const int SUBTASKS = 6;
int main() {
    int number_of_tests[SUBTASKS + 1] = {0, 5, 5, 5, 5, 5, 5};
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
            int n, m;
            std::vector<int> t;
            in >> n >> m;
            t.resize(m);

            for (int i = 0; i < m; i++)
                in >> t[i];

            int x;
            while (in >> x)         // nu exista mai multe numere de atat in vector
                assert(false);

            // -------------------------------------------------------------------------
            //                                  ASSERTS
            // -------------------------------------------------------------------------
            check_correctness(subtask, n, m, t);

            in.close();
        }
    }

    std::cerr << "All tests are correct!\n";
    return 0;
}
