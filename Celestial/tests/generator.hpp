#pragma once
#include <vector>
#include <random>
#include <cassert>
#include <ctime>
#include <functional>

using i64 = long long;
using pairvector = std::vector<std::pair<i64, i64>>;

const int MAX_N = 1e4;
const int MAX_L = 100;
const double MAX_POINT = 5e3;
const double MAX_PHI = M_PI / 2;

class TestData {
public:
    int N, L;
    class Point {
    public:
        double x, y, z;
    };

    class Lantern : public Point {
    public:
        double phi;
    };
    std::vector<Point> stars;
    std::vector<Lantern> lanterns;
    
    TestData() {}
    TestData(int N, int L, std::vector<Point> stars, std::vector<Lantern> lanterns) {
        this->N = N;
        this->L = L;
        this->stars = stars;
        this->lanterns = lanterns;
    }
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
    
    template <typename T>
    T randreal(T l, T r) {
        assert(l <= r);

        std::uniform_real_distribution<T> distr;
        return (distr(rng) * (r - l) + l);
    }
    
    TestData testing();     // For small testing data 
    TestData full();
}
