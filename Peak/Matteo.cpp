#include <bits/stdc++.h>

using namespace std;

struct Fraction {
    long long p, q;

    Fraction() : p(0), q(1) {}

    Fraction(long long p, long long q) : p(p), q(q) { 
        simplify(); 
    }

    Fraction(long long p, const Fraction &q) {
        *this = Fraction(p * q.q, q.p);
    }

    Fraction(const Fraction &numerator, const Fraction &denominator) {
        *this = numerator / denominator;
    }

    void simplify() {
        long long g = __gcd(p, q);
        p /= g;
        q /= g;
    }

    void print() {
        cout << "(" << p << ", " << q << ")\n";
    }

    long long ceil() {
        return (p + q - 1) / q;
    }

    long long floor() {
        return p / q;
    }

    bool operator >= (const int &oth) const {
        return p >= q * oth;
    }

    Fraction& operator -= (const long long &oth) {
        p -= oth * q;
        simplify();
        return *this;
    }

    Fraction operator * (const long long &n) const {
        return Fraction(p * n, q);
    }

    Fraction operator * (const Fraction &oth) const {
        return Fraction(p * oth.p, q * oth.q);
    }

    Fraction operator + (const Fraction &oth) const {
        long long lcm = std::lcm(q, oth.q);
        long long numerator = p * (lcm / q) + oth.p * (lcm / oth.q);
        return Fraction(numerator, lcm);
    }

    Fraction operator - (const Fraction &oth) const {
        long long lcm = std::lcm(q, oth.q);
        long long numerator = p * (lcm / q) - oth.p * (lcm / oth.q);
        return Fraction(numerator, lcm);
    }

    Fraction operator - (const long long &oth) const {
        return Fraction(p - oth * q, q);
    }

    Fraction operator / (const Fraction &oth) const {
        return Fraction(p * oth.q, q * oth.p);
    }
};

long long count_lattices(Fraction k, Fraction b, long long n) {
    auto fk = k.floor();
    auto fb = b.floor();
    auto cnt = 0LL;
    if (k >= 1 || b >= 1) {
        cnt += (fk * (n - 1) + 2 * fb) * n / 2;
        k -= fk;
        b -= fb;
    }
    auto t = (k * n) + b;
    auto ft = t.floor();

    if (ft >= 1) {
        cnt += count_lattices(Fraction(1, k), (t - ft) / k, ft);
    }
    return cnt;
}

long long count_lattices_under(Fraction x1, Fraction y1, Fraction x2, Fraction y2) {
    x2.p -= x1.p; x1.p = 0;
    Fraction k(y2 - y1, x2 - x1);
    Fraction b(y1 * x2 - x1 * y2, x2 - x1);
    long long n = x2.p;

    return count_lattices(k, b, n) + y2.floor() + x2.floor() + 1;
}

long long count_lattices_on(Fraction x1, Fraction y1, Fraction x2, Fraction y2) {
    long long m = std::lcm(y1.q, y2.q);
    long long yy1 = y1.p * m / y1.q;
    long long yy2 = y2.p * m / y2.q;

    return __gcd(x2.p - x1.p, yy2 - yy1) + 1;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        long long a, b, c, d, s, t;
        cin >> a >> b >> c >> d >> s >> t;
        // f(x) = (a/b) * x
        // g(x) = (c/d) * x
        Fraction x1(s, 1), y1(a * s, b);
        Fraction x2(t, 1), y2(a * t, b);
        long long ans1 = count_lattices_under(x1, y1, x2, y2);
        // cout << "Lattice points on/under a/b: " << count_lattices_under(x1, y1, x2, y2) << '\n';

        y1 = Fraction(c * s, d);
        y2 = Fraction(c * t, d);
        long long ans2 = count_lattices_under(x1, y1, x2, y2);
        // cout << "Lattice points on/under c/d: " << count_lattices_under(x1, y1, x2, y2) << '\n';

        // cout << "Lattice points on c/d: " << count_lattices_on(x1, y1, x2, y2) << '\n';
        cout << ans2 - ans1 + count_lattices_on(x1, y1, x2, y2) << '\n';
    }

    return 0;
}
