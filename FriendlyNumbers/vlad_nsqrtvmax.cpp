#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<int> V(N);
  for (int& x : V) {
    cin >> x;
  }

  auto get_decomp = [&](int N) -> vector<pair<int, int>> {
    vector<pair<int, int>> decomp;
    for (int d = 2; d * d <= N; d++) {
      int e = 0;
      while (N % d == 0) {
        e++;
        N /= d;
      }
      if (e > 0) {
        decomp.emplace_back(d, e);
      }
    }
    if (N > 1) {
      decomp.emplace_back(N, 1);
    }
    return decomp;
  };

  auto is_friendly = [&](int N) -> bool {
    if (N == 1) {
      // why
      return true;
    }
    auto decomposition = get_decomp(N);
    return find_if(cbegin(decomposition), cend(decomposition),
      [&](const auto& e) {
        return e.second != decomposition.front().second;
      }
    ) == cend(decomposition);
  };

  int count_friendly = count_if(cbegin(V), cend(V), is_friendly);
  cout << count_friendly * 100 / N << "\n"; // why
  return 0;
}
