// Autor: Theodor Moroianu
// Complexitate: O(M * log(N))

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    size_t N, M;
    cin >> N >> M;
    assert(1 <= N && N <= 200'000);
    assert(1 <= M && M <= 200'000);

    vector<int> t(M);
    for (auto &i : t)
    {
        cin >> i;
        assert(1 <= i && i <= 1'000'000'000);
    }
    reverse(t.begin(), t.end());

    priority_queue<i64> pq;
    while (true)
    {
        i64 when = 0;
        if (pq.size() == N)
        {
            when = -pq.top();
            pq.pop();
        }

        if (t.empty())
            return cout << when << '\n', 0;

        pq.push(-(when + t.back()));
        t.pop_back();
    }
}
