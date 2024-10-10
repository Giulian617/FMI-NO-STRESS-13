#include <bits/stdc++.h>

using namespace std;

long long max1, max2;
struct Fraction {
    long long p, q;

    Fraction() : p(0), q(1) {}

    Fraction(long long p, long long q) : p(p), q(q) { 
        max1 = max(max1, p);
        max2 = max(max2, q);
        if (p % q == 0) {
            p /= q;
            q = 1;
        }
        // simplify(); 
    }

    Fraction(long long p, const Fraction &q) {
        if (p % q.p == 0) {
            *this = Fraction(p / q.p * q.q, 1);
        } else {
            *this = Fraction(p * q.q, q.p);
        }
    }

    Fraction(const Fraction &numerator, const Fraction &denominator) {
        *this = numerator / denominator;
    }

    void simplify() {
        long long g = __gcd(p, q);
        p /= g;
        q /= g;
    }

    long long ceil() {
        return (p + q - 1) / q;
    }

    long long floor() {
        return p / q;
    }

    bool operator >= (const long long &oth) const {
        if (p / q >= oth) return true;
        return p >= q * oth;
    }

    Fraction& operator -= (const long long &oth) {
        p -= oth * q;
        return *this;
    }

    Fraction operator * (const long long &n) const {
        if (n % q == 0) 
            return Fraction(p * (n / q), 1);
        return Fraction(p * n, q);
    }

    Fraction operator * (const Fraction &oth) const {
        Fraction x = *this, y = oth;
        if (x.p == 0 || y.p == 0) return Fraction(0, 1);
        if (x.p % y.q == 0) {
            x.p /= y.q;
            y.q = 1;
        }
        if (x.q % y.p == 0) {
            x.q /= y.p;
            y.p = 1;
        }
        if (y.p % x.q == 0) {
            y.p /= x.q;
            x.q = 1;
        }
        if (y.q % x.p == 0) {
            y.q /= x.p;
            x.p = 1;
        }
        return Fraction(x.p * y.p, x.q * y.q);
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
        return (*this * Fraction(oth.q, oth.p));
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

long long count_lattices_on(Fraction x1, Fraction x2, int a, int b) {
    // Panta este a/b
    // Astfel, vor exista puncte intregi din b / (a, b) in b / (a, b)
    int g = __gcd(a, b);
    b = b / g;
    return (x2.p / b - x1.p / b + (x1.p % b == 0));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        long long a, b, c, d, s, t;
        cin >> a >> b >> c >> d >> s >> t;

        if (s == t) {
            long long l = (long long) a * s / b;
            long long r = (long long) c * s / d;

            if (a * s % b != 0) 
                l++;

            cout << r - l + 1 << '\n';
            continue;
        }

        // f(x) = (a/b) * x
        // g(x) = (c/d) * x
        Fraction x1(s, 1), y1(a * s, b);
        Fraction x2(t, 1), y2(a * t, b);
        long long ans0 = count_lattices_on(x1, x2, a, b);
        long long ans1 = count_lattices_under(x1, y1, x2, y2);
        // cout << "Lattice points on/under a/b: " << count_lattices_under(x1, y1, x2, y2) << '\n';

        y1 = Fraction(c * s, d);
        y2 = Fraction(c * t, d);
        long long ans2 = count_lattices_under(x1, y1, x2, y2);
        // cout << "Lattice points on/under c/d: " << count_lattices_under(x1, y1, x2, y2) << '\n';

        // cout << "Lattice points on a/b: " << ans0 << '\n';
        cout << ans2 - ans1 + ans0 << '\n';
    }

    return 0;
}
