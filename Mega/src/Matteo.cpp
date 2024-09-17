// Matteo Verzotti
// O(M * log(N))
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

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }
    
    for (int i = n; i < m; i++) {
        int x; cin >> x;
        long long min = pq.top();
        pq.pop();
        pq.push(min + x);
    }

    cout << pq.top() << '\n';
    return 0;
}
