// Matteo Verzotti - Subtask 5
// O(N * M)
#include <algorithm>
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
    int n, m;
    cin >> n >> m;
    
    if (m < n) {
        cout << "0\n";
        return 0;
    }

    vector<int> v(m), t(n);
    for (int i = 0; i < m; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        t[i] = v[i];
    
    long long ans = 0;
    for (int i = n; i < m; i++) {
        int min = *min_element(t.begin(), t.end());
        int idx = min_element(t.begin(), t.end()) - t.begin();
        ans += min;

        for (int j = 0; j < n; j++)
            t[j] -= min;
        t[idx] = v[i];
    }

    cout << ans + *min_element(t.begin(), t.end()) << '\n';
    return 0;
}
