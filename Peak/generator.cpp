#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

int main() {
    int q = 1;
    cout << q << '\n';

    while (q--) {
        int a = randint(1, 1000);
        int b = randint(1, 1000);
        int c = randint(1, 1000);
        int d = randint(1, 1000);
        int s = randint(1, 1000);
        int t = randint(1, 1000);
        
        // make sure a/b < c/d
        if (a * d > b * c) {
            swap(a, c);
            swap(b, d);
        }
        if (s > t) swap(s, t);

        cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << s << ' ' << t << '\n';
    }
    return 0;
}
