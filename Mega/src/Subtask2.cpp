// Matteo Verzotti - Subtask 2
// O(M)
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
    vector<int> v(m);
    for (int i = 0; i < m; i++)
        cin >> v[i];
    
    cout << *min_element(v.begin(), v.end()) << '\n';
    return 0;
}
