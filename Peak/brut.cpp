#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d, s, t;
        long long cnt = 0;
        cin >> a >> b >> c >> d >> s >> t;
        for (int y = s; y <= t; y++) {
            long long l = (long long) a * y / b;
            long long r = (long long) c * y / d;

            if (a * y % b != 0) 
                l++;

            // cout << y << ' ' << l << ' ' << r << '\n';

            cnt += r - l + 1;
        }

        cout << cnt << '\n';
    }
    return 0;
}
