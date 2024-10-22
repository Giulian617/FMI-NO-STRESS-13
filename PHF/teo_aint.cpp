// Autor: Theodor Moroianu
// Complexitate: O((N + Q) log)
// Indented: 100 puncte

#include <bits/stdc++.h>
using namespace std;

int Win(int a, int b)
{
    if (a == (b + 1) % 3)
        return a;
    return b;
}

struct Aint
{
    vector<array<int, 3>> aint;
    int first_elem;
    int N;

    void update(int node, int l, int r, int poz, int val)
    {
        if (l > poz || r < poz)
            return;
        if (l == r)
        {
            for (int i = 0; i < 3; i++)
                aint[node][i] = Win(i, val);
            return;
        }

        int m = (l + r) / 2;
        int sz_left = m - l + 1;
        update(node + 1, l, m, poz, val);
        update(node + 2 * sz_left, m + 1, r, poz, val);
        for (int i = 0; i < 3; i++)
            aint[node][i] = aint[node + 2 * sz_left][aint[node + 1][i]];
    }

    void Update(int poz, int val)
    {
        if (poz == 0)
            first_elem = val;
        update(1, 0, N - 1, poz, val);
    }

    int Query()
    {
        return aint[1][first_elem];
    }

    Aint(int N) : N(N)
    {
        aint.resize(4 * N);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string ops = "PHF";
    auto ReadElem = [&]()
    {
        char c;
        cin >> c;
        return ops.find(c);
    };

    int N, Q;
    cin >> N >> Q;

    Aint aint(N);
    for (int i = 0; i < N; i++)
        aint.Update(i, ReadElem());

    vector<int> win_str = {aint.aint[1][aint.first_elem]};

    while (Q--)
    {
        int poz;
        cin >> poz;
        aint.Update(poz - 1, ReadElem());
        win_str.push_back(aint.Query());
    }

    for (auto i : win_str)
        cout << ops[i];
    cout << '\n';
}