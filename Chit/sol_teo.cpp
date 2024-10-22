// Autor: Theodor Moroianu
// Complexitate: O(N + M)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    assert(3 <= N && N <= 100'000);
    assert(2 <= M && M <= 100'000);
    vector<int> sum(N);

    while (M--)
    {
        int a, b;
        cin >> a >> b;
        assert(a >= 1 && a <= N);
        assert(b >= 1 && b <= N);
        sum[a - 1]++, sum[b - 1]--;
    }

    bool ok = true;
    for (auto i : sum)
        ok &= (i == 0);

    cout << (ok ? "Chit" : "Datorii") << '\n';
}
