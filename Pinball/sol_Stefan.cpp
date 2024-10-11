#include <bits/stdc++.h>

using namespace std;

const int NMAX = 105;

vector<pair<int, int>> adj[NMAX];

template <long long MD>
class Modular{
    long long num;
public:
    Modular(long long num = 0): num(num % MD) {
        assert(num >= 0); // asta n-are cum sa se intample wtf
    }
    inline Modular operator+(const Modular& ot) const {
        return Modular(num + ot.num);
    }
    inline Modular operator-(const Modular& ot) const {
        return Modular(num - ot.num + MD);
    }
    inline Modular operator*(const Modular& ot) const {
        return Modular(num * ot.num);
    }
    inline Modular operator/(const Modular& ot) const {
        return Modular(num * ot.inv().num);
    }
    inline Modular inv() const {
        long long q = MD - 2, x = num, ans = 1;
        while(q){
            if(q & 1)
                ans = (ans * x) % MD;
            x = (x * x) % MD;
            q >>= 1;
        }
        return Modular(ans);
    }
    inline bool operator==(const Modular& ot) const {
        return num == ot.num;
    }
    inline bool operator!=(const Modular& ot) const {
        return num != ot.num;
    }
    inline friend ostream& operator<<(ostream& out, const Modular& m){
        return out << m.num;
    }
};

const int MOD = 1e9 + 7;
using ModType = Modular<MOD>;

class Matrix{
    vector<vector<ModType>> mat;
public:
    Matrix(int n, int m): mat(n, vector<ModType>(m)){}
    Matrix(vector<ModType> v): mat((int)v.size(), vector<ModType>(1)){
        for(int i = 0; i < (int)v.size(); i++)
            mat[i][0] = v[i];
    }
    Matrix operator*(const Matrix& ot) const {
        assert(mat[0].size() == ot.mat.size());
        Matrix ans(mat.size(), ot.mat[0].size());
        for(int i = 0; i < (int)mat.size(); i++)
            for(int j = 0; j < (int)ot.mat[0].size(); j++)
                for(int k = 0; k < (int)ot.mat.size(); k++)
                    ans.mat[i][j] = ans.mat[i][j] + mat[i][k] * ot.mat[k][j];
        return ans;
    }
    Matrix exp(long long e) const {
        assert(mat.size() == mat[0].size());
        Matrix ans(mat.size(), mat.size());
        Matrix base = *this;
        for(int i = 0; i < (int)mat.size(); i++)
            ans.mat[i][i] = ModType(1);
        while(e){
            if(e & 1)
                ans = ans * base;
            base = base * base;
            e >>= 1;
        }
        return ans;
    }
    vector<ModType>& operator[](int idx){
        return mat[idx];
    }
    const vector<ModType>& operator[](int idx) const {
        return mat[idx];
    }
    int size() const {
        return mat.size();
    }
    friend ostream& operator<<(ostream& out, const Matrix& m){
        for(int i = 0; i < m.size(); i++){
            for(int j = 0; j < (int)m[i].size(); j++)
                out << m[i][j] << ' ';
            out << '\n';
        }
        return out;
    }
};


unordered_map<int, int> node_to_leaf_idx;
unordered_map<int, int> leaf_idx_to_node;

void dfs(int nod, int par, vector<ModType> & dp){ // decy, sunt in nodul asta si ma duc in jos si calculez probabilitati
    auto curSum = ModType(0);
    for(auto &[nxt, w]: adj[nod])
        if(nxt != par){
            curSum = curSum + ModType(w);
        }
    curSum = curSum.inv();
    for(auto &[nxt, w]: adj[nod])
        if(nxt != par){
            dp[nxt] = dp[nod] * ModType(w) * curSum;
            dfs(nxt, nod, dp);
        }
}

vector<ModType> getProbs(int node, int num_nodes){
    // decy, nodul asta e -1 daca e radacina aia prima (adica 0),
    // sau e numar pozitiv daca ii dau indexul in sirul ala de frunze
    vector<ModType> dp(num_nodes);
    vector<ModType> ans((int)node_to_leaf_idx.size());
    int realNode = (node == -1 ? 0 : leaf_idx_to_node[node]);
    dp[realNode] = ModType(1);
    dfs(realNode, -1, dp);
    for(int i = 0; i < (int)ans.size(); i++){
        ans[i] = dp[leaf_idx_to_node[i]];
    }

    if(node_to_leaf_idx.find(realNode) == node_to_leaf_idx.end()){ // radacina e frunza
        ans[node_to_leaf_idx[realNode]] = ModType(0);
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    long long k;
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++){
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    for(int i = 0; i < n; i++){
        if((int)adj[i].size() == 1){
            node_to_leaf_idx[i] = (int)leaf_idx_to_node.size();
            leaf_idx_to_node[(int)leaf_idx_to_node.size()] = i;
        }
    }

    auto damnMatrix = Matrix((int)node_to_leaf_idx.size(), (int)node_to_leaf_idx.size());

    for(int i = 0; i < n; i++){
        if((int)adj[i].size() == 1){
            auto t = getProbs(node_to_leaf_idx[i], n);
            for(int j = 0; j < (int)t.size(); j++){
                damnMatrix[j][node_to_leaf_idx[i]] = t[j];
            }
        }
    }
    auto damnVector = Matrix(getProbs(-1, n));

    auto finalMatrix = damnMatrix.exp(k) * damnVector;

    for(int i = 0; i < (int)leaf_idx_to_node.size(); i++){
        cout << finalMatrix[i][0] << "\n";
    }
    return 0;
}
