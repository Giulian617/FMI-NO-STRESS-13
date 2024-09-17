// Matteo Verzotti - Subtask 4
// O(1)
#include <bits/stdc++.h>
#ifdef BLAT
    #include "debug/debug.hpp"
#else
    #define debug(x...)
#endif

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t0;
    cin >> n >> m >> t0;

    cout << 1LL * t0 * (m / n) << '\n';
    return 0;
}
