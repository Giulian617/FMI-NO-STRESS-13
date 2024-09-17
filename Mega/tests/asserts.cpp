#include <bits/stdc++.h>

const int MAX_N = 2e5;
const int MAX_M = 2e5;
const int MAX_T = 1e9;

void check_correctness(int subtask, long long n, int q, std::vector<std::pair<long long, long long>> &vq) {
    assert(1 <= n && n <= NMAX);
    assert(1 <= q && q <= Q);

    for (auto i : vq)
        assert(i.first <= i.second && 1 <= i.first && i.first <= n && 1 <= i.second && i.second <= n);

    switch (subtask) {
        case 1:
            assert(n <= 9);
            break;

        case 2:
            assert(n <= 17);
            break;

        case 3:
            assert(q == 1);
            break;

        case 4:
            for (int i = 0; i < q; i++)
                assert(vq[i].second == n);
            break;

        case 5:
            assert(n <= 1000000);

            sort(vq.begin(), vq.end());
            for (int i = 2; i < vq.size(); i++)
                assert(vq[i - 1].second < vq[i].first);

            break;

        case 6:
            assert(n <= 1000000);
            break;
    }
}

int main() {
    int number_of_tests[] = {0, 3, 5, 4, 6, 6, 5, 18};
    std::ifstream in;

    for (int subtask = 1; subtask <= 7; subtask++) {
        std::string filename = "Full/Subtask_", currdir;
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
            long long n;
            int q;
            std::vector<std::pair<long long, long long>> vq;
            in >> n >> q;
            vq.resize(q);

            for (int i = 0; i < q; i++)
                in >> vq[i].first >> vq[i].second;

            int x;
            while (in >> x) // nu exista mai multe numere de atat in vector
                assert(false);

            // -------------------------------------------------------------------------
            //                                  ASSERTS
            // -------------------------------------------------------------------------
            check_correctness(subtask, n, q, vq);

            in.close();
        }
    }

    std::cerr << "All tests are correct!\n";
    return 0;
}
