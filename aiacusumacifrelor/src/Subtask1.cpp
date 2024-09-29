// Matteo - 70p
// O(Q)
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

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x % 9 == 0) cout << "0\n";
        else if (x % 9 == 1 || x % 9 == 5 || x % 9 == 8) cout << "2\n";
        else cout << "1\n";
    }
    return 0;
}
