// Matteo
// O(N^3 * K)
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

struct Matrix {
    int n;
    vector<vector<int>> a;

    Matrix(int _n) : n(_n) {
        a.resize(1 + n, vector<int>(1 + n));
    }
    
    vector<int>& operator [](int i) {
        return a[i];
    }

    const vector<int>& operator [](int i) const {
        return a[i];
    }

    Matrix operator *(const Matrix &other) {
        Matrix res(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    res[i][j] = (res[i][j] + (1LL * a[i][k] * other[k][j] % MOD)) % MOD;
        return res;
    }
};

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
    Matrix prob(n);
        
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1 || i == 1) {
            prob[i][i] = 1;
            dfs(i, 0, g, prob[i]);
            prob[i][i] = 0;

            for (int j = 1; j <= n; j++)
                if (g[j].size() > 1)
                    prob[i][j] = 0;
        }
    
    Matrix p0 = prob;
    for (int i = 1; i <= k; i++) {
        prob = prob * p0;
    }

    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1) {
            cout << prob[1][i] << '\n';
        }
    return 0;
}

/*
4 5
2 3 2
2 4 2
1 2 1

Pentru K > 0, cand vrem sa calculam probabilitatea ca la al K-lea pas
sa ajungem din i in j.

prob[i,j,k] = suma(prob[i,j0,k-1] * prob[j0,j,k-1])

prob[1,1,1] = prob[1,2,0] * prob[2,1,0]
            + prob[1,3,0] * prob[3,1,0]
            + prob[1,4,0] * prob[4,1,0]
*/

