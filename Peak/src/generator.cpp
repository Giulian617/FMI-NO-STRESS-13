#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

int main() {
    // int q = randint(1, 100000);
    int q = 1;
    cout << q << '\n';

    while (q--) {
        int a = randint(1, 10);
        int b = randint(1, 5);
        int c = randint(1, 10);
        int d = randint(1, 5);
        int g = std::lcm(b, d);
        int s = randint(1, 50 / g) * g;
        int t = randint(1, 50 / g) * g;
        
        // make sure a/b < c/d
        if (1LL * a * d > 1LL * b * c) {
            swap(a, c);
            swap(b, d);
        }
        if (s > t) swap(s, t);

        cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << s << ' ' << t << '\n';
    }
    return 0;
}
