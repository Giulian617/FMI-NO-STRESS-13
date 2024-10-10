#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-6;

long long count_lattices(double k, double b, long long n) {
    auto fk = floor(k + EPS);
    auto fb = floor(b + EPS);
    auto cnt = 0LL;
    if (k >= 1 || b >= 1) {
        cnt += (fk * (n - 1) + 2 * fb) * n / 2;
        k -= fk;
        b -= fb;
    }
    auto t = (k * n) + b;
    auto ft = floor(t + EPS);

    if (ft >= 1) {
        cnt += count_lattices(1.0 / k, (t - ft) / k, ft);
    }
    return cnt;
}

long long count_lattices_under(double x1, double y1, double x2, double y2) {
    x2 -= x1; x1 = 0;
    double k = (y2 - y1) / x2;
    double b = (y1 * x2 - x1 * y2) / x2;
    long long n = round(x2);

    return count_lattices(k, b, n) + floor(y2 + EPS) + floor(x2 + EPS) + 1;
}

long long count_lattices_on(double x1, double x2, int a, int b) {
    // Panta este a/b
    // Astfel, vor exista puncte intregi din b / (a, b) in b / (a, b)
    int g = __gcd(a, b);
    int x11 = round(x1), x22 = round(x2);
    b = b / g;
    return (x22 / b - x11 / b + (x11 % b == 0));
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
        double x1 = s, y1 = (double)a * s / b;
        double x2 = t, y2 = (double)a * t / b;
        long long ans0 = count_lattices_on(x1, x2, a, b);
        long long ans1 = count_lattices_under(x1, y1, x2, y2);
        // cout << "Lattice points on/under a/b: " << count_lattices_under(x1, y1, x2, y2) << '\n';

        y1 = (double)c * s / d;
        y2 = (double)c * t / d;
        long long ans2 = count_lattices_under(x1, y1, x2, y2);
        // cout << "Lattice points on/under c/d: " << count_lattices_under(x1, y1, x2, y2) << '\n';

        // cout << "Lattice points on a/b: " << ans0 << '\n';
        cout << ans2 - ans1 + ans0 << '\n';
    }

    return 0;
}
