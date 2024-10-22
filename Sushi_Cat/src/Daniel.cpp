#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int mult(int a, int b) {
    return 1ll * a * b % MOD;
}

void addTo(int& a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int lgput(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = mult(ans, a);
        a = mult(a, a);
        b /= 2;
    }
    return ans;
}

int invMod(int a) {
    return lgput(a, MOD - 2);
}

struct Matrix {
    vector <vector <int>> m;
    int N, M;
    Matrix(int N, int M) : N(N), M(M) {
        m = vector <vector <int>> (N, vector <int> (M));
    }
    void changeValue(int i, int j, int val) {
        assert(0 <= i && i < N);
        assert(0 <= j && j < M); 
        m[i][j] = val;
    }
    Matrix operator * (const Matrix& other) const {
        assert(M == other.N);
        Matrix answer(N, other.M);
        for (int i = 0; i < N; i++)
            for (int k = 0; k < M; k++) {
                for (int j = 0; j < other.M; j++) {
                    addTo(answer.m[i][j], mult(m[i][k], other.m[k][j]));
                }
            }
        return answer;
    }
    Matrix operator ^ (int e) const {
        assert(M == N);
        Matrix answer(N, M);
        for (int i = 0; i < N; i++)
            answer.m[i][i] = 1;
        Matrix base = *this;
        while (e > 0) {
            if (e & 1)
                answer = answer * base;
            base = base * base;
            e /= 2;
        }
        return answer;
    }
};

const int MAX_N = 300;
vector <pair <int, int>> graph[MAX_N];

int prob[MAX_N][MAX_N];

void dfs(int root, int node, int par, int p) {
    if (graph[node].size() == 1 && node != root) {
        prob[root][node] = p;
    }
    int totalSum = 0;
    for (pair <int, int> e : graph[node]) {
        int w = e.second;
        int neigh = e.first;
        if (neigh != par) {
            totalSum += w;
        }
    }
    for (pair <int, int> e : graph[node]) {
        int w = e.second;
        int neigh = e.first;
        if (neigh != par) {
            int newP = mult(mult(p, w), invMod(totalSum));
            dfs(root, neigh, node, newP);
        }
    }
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w; u--, v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int root = 0;
    for (int i = 0; i < N; i++) {
        if (i == root || graph[i].size() == 1) {
            dfs(i, i, -1, 1);
        }
    }
    Matrix probs(N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            probs.m[i][j] = prob[i][j];
    probs = (probs ^ (K + 1));
    for (int i = 0; i < N; i++)
        if (graph[i].size() == 1) {
            // 0 to that leaf
            cout << probs.m[0][i] << "\n";
        }
    return 0;
}
