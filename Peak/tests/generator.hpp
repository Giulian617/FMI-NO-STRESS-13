#pragma once
#include <vector>
#include <random>
#include <cassert>
#include <ctime>
#include <functional>

using i64 = long long;
using pairvector = std::vector<std::pair<i64, i64>>;

const int MAX_Q = 1e5;
const int MAX_F = 100;
const int MAX_V = 1e7;

class TestData {
public:
    int Q;
    struct Query {
        int a, b, c, d, s, t;

        void correct() {
            if (1LL * a * d > 1LL * b * c) {
                std::swap(a, c);
                std::swap(b, d);
            }
            if (s > t) std::swap(s, t);
        }
    };
    std::vector<Query> v;
    
    TestData() {}
    TestData(int Q, std::vector<Query> v) : Q(Q), v(v) {}
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
    TestData subtask1();    // t - s <= 10^3
    TestData Pick();        // (b, d) | s,t
    TestData full();
}
