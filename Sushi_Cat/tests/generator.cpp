#include <bits/stdc++.h>
#include "generator.hpp"

namespace Generator {
    std::random_device rd;
    std::mt19937_64 rng(rd());

    std::vector<i64> generateRandomVector(int size, i64 MIN_VAL = 1LL, i64 MAX_VAL = MAX_X) {
        std::vector<i64> v;
        for (int i = 0; i < size; i++)
            v.push_back(rand(MIN_VAL, MAX_VAL));

        return v;
    }

    // For small testing data
    TestData testing() {
        int q;
        std::vector<i64> x;
        q = rand(1, 10);
        x = generateRandomVector(q, 1, 100);

        return TestData(q, x);
    }

    // x <= 10^9
    TestData subtask1() {
        int q;
        std::vector<i64> x;
        q = rand(1, MAX_Q);
        x = generateRandomVector(q, 1, 1e9);

        return TestData(q, x);
    }

    TestData full() {
        int q;
        std::vector<i64> x;
        q = rand(1, MAX_Q);
        x = generateRandomVector(q, 1LL, MAX_X);

        return TestData(q, x);
    }
}
