// Matteo - Subtask 2
// Teorema lui Pick
#include <bits/stdc++.h>

using namespace std;

long long count_lattices_on(pair<int, int> A, pair<int, int> B, int a, int b) {
    // Panta este a/b
    // Astfel, vor exista puncte intregi din b / (a, b) in b / (a, b)
    int g = __gcd(a, b);
    int x1 = A.first, x2 = B.first;
    b = b / g;
    return (x2 / b - x1 / b + (x1 % b == 0));
}

long long arieTrapez(int baza1, int baza2, int h) {
    return 1LL * (baza1 + baza2) * h / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d, s, t;
        cin >> a >> b >> c >> d >> s >> t;

        assert(s % b == 0);
        assert(s % d == 0);
        pair<int, int> A, B, C, D;

        A = make_pair(s, a * (s / b));
        B = make_pair(t, a * (t / b));
        C = make_pair(t, c * (t / d));
        D = make_pair(s, c * (s / d));
        
        long long border = count_lattices_on(A, B, a, b) + count_lattices_on(D, C, c, d);
        border += (D.second - A.second - 1) + (C.second - B.second - 1);

        // Area = i + b / 2 - 1
        long long arie = arieTrapez(D.second - A.second, C.second - B.second, t - s);
        long long interior = arie + 1 - border / 2;
        cout << interior + border << '\n';
    }

    return 0;
}
