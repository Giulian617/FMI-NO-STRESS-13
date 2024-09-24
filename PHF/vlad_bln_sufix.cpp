#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <map>

using namespace std;

const vector<string> result = {"aba", "bbc", "acc"};

inline char play(const char a, const char b) {
  return result[a - 'a'][b - 'a'];
}

char get_answer(string_view ops) {
  char winner = ops[0];
  for (const auto opponent : ops) {
    winner = play(winner, opponent);
  }
  return winner;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  int L = min(N, 100);

  map<char, char> who;
  who['a'] = 'P';
  who['b'] = 'H';
  who['c'] = 'F';
  who['P'] = 'a';
  who['H'] = 'b';
  who['F'] = 'c';

  for (char& c : S) {
    c = who[c];
  }

  auto winner = get_answer(S.c_str());
  for (int q = 0; q < Q; q++) {
    int pos;
    char c;
    cin >> pos >> c;
    pos--;
    c = who[c];
    S[pos] = c;
    winner = get_answer(S.c_str() + N - L);
    cout << who[winner];
  }
  cout << "\n";
  return 0;
}
