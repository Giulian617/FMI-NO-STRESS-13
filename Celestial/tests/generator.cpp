#include <bits/stdc++.h>
#include "generator.hpp"

namespace Generator {
    std::random_device rd;
    std::mt19937_64 rng(rd());
    
    TestData generateRandom(int MAX_N, int MAX_L, double MAX_POINT, double MAX_PHI) {
        int N = rand(1, MAX_N);
        int L = rand(1, MAX_L);
        std::vector<TestData::Point> stars;
        for (int i = 0; i < N; i++) {
            stars.push_back({randreal(0.0, MAX_POINT), randreal(0.0, MAX_POINT), randreal(0.0, MAX_POINT)});
        }
        std::vector<TestData::Lantern> lanterns;
        for (int i = 0; i < L; i++) {
            lanterns.push_back({randreal(0.0, MAX_POINT), randreal(0.0, MAX_POINT), randreal(0.0, MAX_POINT), randreal(0.0, MAX_PHI)});
        }

        return TestData(N, L, stars, lanterns);
    }

    // For small testing data
    TestData testing() {
        return generateRandom(5, 5, 10, MAX_PHI);
    }
    
    TestData full() {
        return generateRandom(MAX_N, MAX_L, MAX_POINT, MAX_PHI);
    }
}
