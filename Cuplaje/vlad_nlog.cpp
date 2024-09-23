#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<pair<int, int>> events(2 * N);
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    events[i] = pair{x, 1};
  }
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    events[i + N] = pair{x, -1};
  }

  sort(begin(events), end(events));
  int waiting = 0;
  for (const auto& [_pos, type] : events) {
    waiting += type;
    waiting = max(0, waiting);
  }
  cout << waiting << "\n";
  return 0;
}
