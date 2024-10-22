// Autor: Theodor Moroianu
// Complexitate: O(1)
// Indented: 100 puncte

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int Q;
    cin >> Q;

    vector<int> costs = {0, 2, 1, 1, 1, 2, 1, 1, 2};

    while (Q--)
    {
        i64 n;
        cin >> n;
        cout << costs[n % 9] << '\n';
    }
}