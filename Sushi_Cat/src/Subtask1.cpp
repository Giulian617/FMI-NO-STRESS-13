// Matteo - Subtask 1
// O(N^2)
#include <bits/stdc++.h>
#ifdef BLAT
    #include "debug/debug.hpp"
#else
    #define debug(x...)
#endif

using namespace std;

const int MOD = 1e9 + 7;

void euclid(const int a, const int b, int &x1, int &y1) {
    if (b == 0) {
        x1 = y1 = 1;
        return;
    }
    int x2, y2;
    euclid(b, a % b, x2, y2);

    x1 = y2;
    y1 = (x2 - a / b * y2) % MOD;
}

int modInv(const int q) {
    int x1, y1;
    euclid(q, MOD, x1, y1);

    if (x1 < 0)
        x1 += MOD;
    return x1;
}

using Graph = vector<vector<pair<int, int>>>;

void dfs(int node, int parent, const Graph &g, vector<int> &prob) {
    int sum_w = 0;
    for (auto &[son, w] : g[node]) {
        if (son == parent) continue;
        sum_w += w;
    }
    
    for (auto &[son, w] : g[node]) {
        if (son == parent) continue;
        prob[son] = (1LL * prob[node] * w) % MOD * modInv(sum_w) % MOD;
        dfs(son, node, g, prob);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long k;
    cin >> n >> k;
    Graph g(1 + n);
    for (int i = 1; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back(make_pair(y, w));
        g[y].push_back(make_pair(x, w));
    }
    // prob[i][j] = probabilitatea ca daca pornind de la frunza i, 
    // se ajunge in frunza j
    vector<vector<int>> prob(1 + n, vector<int>(1 + n));
        
    prob[1][1] = 1;
    dfs(1, 0, g, prob[1]);
    prob[1][1] = 0;
    for (int i = 2; i <= n; i++)
        if (g[i].size() == 1) {
            prob[i][i] = 1;
            dfs(i, 0, g, prob[i]);
            prob[i][i] = 0;
        }
    
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1) {
            cout << prob[1][i] << '\n';
        }
    return 0;
}

/*
4 0
2 3 2
2 4 2
1 2 1
*/


