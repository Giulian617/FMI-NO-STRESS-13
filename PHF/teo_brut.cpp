// Autor: Theodor Moroianu
// Complexitate: O(N * Q)
// Indented: 60 puncte

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    array<array<char, 256>, 256> win;
    string ops = "PFHP";
    for (int i = 0; i < 3; i++)
    {
        win[ops[i]][ops[i]] = ops[i];
        win[ops[i]][ops[i + 1]] = ops[i];
        win[ops[i + 1]][ops[i]] = ops[i];
    }

    int N, Q;
    cin >> N >> Q;

    string state;
    cin >> state;

    auto ComputeWinner = [&]()
    {
        char winner = state[0];
        for (auto c : state)
            winner = win[winner][c];
        return winner;
    };

    string win_str(1, ComputeWinner());

    while (Q--)
    {
        int poz;
        char new_chr;
        cin >> poz >> new_chr;
        state[poz - 1] = new_chr;
        win_str += ComputeWinner();
    }

    cout << win_str << endl;
}