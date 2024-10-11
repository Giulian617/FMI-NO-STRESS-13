#pragma once
#include <vector>
#include <random>
#include <cassert>
#include <ctime>
#include <functional>

using i64 = long long;

const int MAX_Q = 1e5;
const i64 MAX_X = 1e18;

class TestData {
public:
    int q;
    std::vector<i64> x;
    
    TestData() {}
    TestData(int q, std::vector<i64> x) : q(q), x(x) {}
    TestData(std::function<TestData(void)> func);
};

namespace Generator {
    extern std::random_device rd;
    extern std::mt19937_64 rng;

    template <typename T>
    T rand(T l, T r) {
        assert(l <= r);

        std::uniform_int_distribution<T> distr;
        return (distr(rng) % (r - l + 1) + l);
    }
    
    TestData testing();     // For small testing data
    TestData subtask1();    // x <= 10^9
    TestData full();        // x <= 10^18
}
