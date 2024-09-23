#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  vector<int> delta(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    delta[u]++;
    delta[v]--;
  }

  cout << ((count_if(cbegin(delta), cend(delta), [&](int x) { return x != 0; })) == 0 ? "Chit" : "Datorii") << "\n";
  return 0;
}
