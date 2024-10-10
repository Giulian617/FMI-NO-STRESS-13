#include <bits/stdc++.h>
#include "generator.hpp"

namespace Generator {
    std::random_device rd;
    std::mt19937_64 rng(rd());
    
    std::vector<TestData::Query> generateRandomVector(int size, int MIN_VAL = 1, int MAX_VAL = MAX_V) {
        std::vector<TestData::Query> v;
        for (int i = 0; i < size; i++) {
            TestData::Query q;
            q.a = rand(MIN_VAL, MAX_F);
            q.b = rand(MIN_VAL, MAX_F);
            q.c = rand(MIN_VAL, MAX_F);
            q.d = rand(MIN_VAL, MAX_F);
            q.s = rand(MIN_VAL, MAX_VAL);
            q.t = rand(MIN_VAL, MAX_VAL);
            q.correct();
            v.push_back(q);
        }

        return v;
    }

    // For small testing data
    TestData testing() {
        auto v = generateRandomVector(1, 1, 10);
        for (auto &q : v) {
            q.a = rand(1, 10);
            q.b = rand(1, 10);
            q.c = rand(1, 10);
            q.d = rand(1, 10);
            q.correct();
        }
        return TestData(1, v);
    }
    
    // t - s <= 10^3
    TestData subtask1() {
        int Q = rand(1, MAX_Q);
        auto v = generateRandomVector(Q);
        for (auto &q : v) {
            q.s = rand(1, MAX_V);
            q.t = std::min(MAX_V, q.s + rand(1, 1000));
        }
        return TestData(Q, v);
    }

    // s and t are divisible by lcm(b, d)
    TestData Pick() {
        int Q = rand(1, MAX_Q);
        auto v = generateRandomVector(Q);
        for (auto &q : v) {
            int g = std::lcm(q.b, q.d);
            q.s = rand(1, MAX_V / g) * g;
            q.t = rand(1, MAX_V / g) * g;

            if (q.s > q.t)
                std::swap(q.s, q.t);
        }
        return TestData(Q, v);
    }

    TestData full() {
        int Q = MAX_Q;
        auto v = generateRandomVector(Q);
        return TestData(Q, v);
    }
}
