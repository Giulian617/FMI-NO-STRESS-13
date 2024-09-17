#pragma once
#include <vector>
#include <random>
#include <cassert>
#include <ctime>
#include <functional>

using i64 = long long;
using pairvector = std::vector<std::pair<i64, i64>>;

const int MAX_N = 2e5;
const int MAX_M = 2e5;
const int MAX_T = 1e9;

class TestData {
public:
    int n, m;
    std::vector<int> t;
    
    TestData() {}
    TestData(int n, int m, std::vector<int> t) : n(n), m(m), t(t) {}
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
    TestData subtask1();    // M < N 
    TestData subtask2();    // M = N
    TestData subtask3();    // N = 1
    TestData subtask4();    // t[i] equal
    TestData subtask5();    // M <= 2000
    TestData full();
}
