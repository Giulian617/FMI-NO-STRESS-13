#include <bits/stdc++.h>
#include "generator.hpp"

namespace Generator {
    std::random_device rd;
    std::mt19937_64 rng(rd());
    
    std::vector<int> generateRandomVector(int size, int MIN_VAL = 1, int MAX_VAL = MAX_T) {
        std::vector<int> v;
        for (int i = 0; i < size; i++)
            v.push_back(rand(1, MAX_VAL));

        return v;
    }

    // For small testing data
    TestData testing() {
        int n, m;
        std::vector<int> t;
        n = rand(1, 5); 
        m = rand(1, 10);
        t = generateRandomVector(m, 1, 10);

        return TestData(n, m, t);
    }
    
    // M < N
    TestData subtask1() {
        int n, m;
        std::vector<int> t;

        n = rand(2, MAX_N);
        m = rand(1, n - 1); 
        t = generateRandomVector(m);

        return TestData(n, m, t);
    }

    // M = N
    TestData subtask2() {
        int n, m;
        std::vector<int> t;

        n = rand(1, MAX_N);
        m = n;
        t = generateRandomVector(m);

        return TestData(n, m, t);
    }

    // N = 1
    TestData subtask3() {
        int n, m;
        std::vector<int> t;

        n = 1;
        m = rand(1, MAX_M);
        t = generateRandomVector(m);

        return TestData(n, m, t);
    }

    // t[i] equal
    TestData subtask4() {
        int n, m;
        std::vector<int> t;

        n = rand(1, MAX_N);
        m = rand(n, MAX_M);
        int t0 = rand(1, MAX_T);
        t.resize(m, t0);

        return TestData(n, m, t);
    }

    // M <= 2000
    TestData subtask5() {
        int n, m;
        std::vector<int> t;

        n = rand(1, 2000);
        m = rand(n, 2000);
        t = generateRandomVector(m, MAX_T - 10000, MAX_T);

        return TestData(n, m, t);
    }
    
    TestData full() {
        int n, m;
        std::vector<int> t;

        n = rand(1, MAX_N);
        m = rand(std::max(n, MAX_M - 1000), MAX_M);
        t = generateRandomVector(m, MAX_T - 10000, MAX_T);

        return TestData(n, m, t);
    }
}
