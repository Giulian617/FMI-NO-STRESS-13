#include <bits/stdc++.h>
#include <numeric>
#include "generator.hpp"

void check_correctness(int subtask, TestData &data) {
    auto [Q, v] = data;
    assert(1 <= Q && Q <= MAX_Q);

    for (auto vi : v) {
        assert(1 <= vi.a && vi.a <= MAX_F);
        assert(1 <= vi.b && vi.b <= MAX_F);
        assert(1 <= vi.c && vi.c <= MAX_F);
        assert(1 <= vi.d && vi.d <= MAX_F);
        assert(1 <= vi.s && vi.s <= MAX_V);
        assert(1 <= vi.t && vi.t <= MAX_V);
        assert(1LL * vi.a * vi.d <= 1LL * vi.b * vi.c);
        assert(vi.s <= vi.t);
    }

    switch (subtask) {
        case 1:
            for (auto vi : v)
                assert(vi.t - vi.s <= 1000);
            break;

        case 2:
            for (auto vi : v) {
                int g = std::lcm(vi.b, vi.d);
                assert(vi.s % g == 0);
                assert(vi.t % g == 0);
            }
            break;
    }
}

const int SUBTASKS = 3;
int main() {
    int number_of_tests[SUBTASKS + 1] = {0, 10, 10, 10};
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
            in >> data.Q;
            data.v.resize(data.Q);

            for (int i = 0; i < data.Q; i++) {
                auto &vi = data.v[i];
                in >> vi.a >> vi.b >> vi.c >> vi.d >> vi.s >> vi.t;
            }

            int x;
            while (in >> x)         // nu exista mai multe numere de atat in vector
                assert(false);

            // -------------------------------------------------------------------------
            //                                  ASSERTS
            // -------------------------------------------------------------------------
            check_correctness(subtask, data);

            in.close();
        }
    }

    std::cerr << "All tests are correct!\n";
    return 0;
}
