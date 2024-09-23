#include <iostream>
#include <vector>
#include <utility>
#include <numeric>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> mat(N, vector<int>(M));
  for (auto& member : mat) {
    for (int& x : member) {
      cin >> x;
    }
  }

  auto line_sum = [&](int i) { return accumulate(mat[i].begin(), mat[i].end(), 0); };

  auto answer = pair{0, 0};
  for (int i = 1; i < N; i++) {
    if (line_sum(i) < line_sum(answer.first)) {
      answer.first = i;
    }
    if (line_sum(i) > line_sum(answer.second)) {
      answer.second = i;
    }
  }
  cout << answer.first + 1 << " " << answer.second + 1 << "\n";
  return 0;
}
