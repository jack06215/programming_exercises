#include <iostream>
#include <vector>
#include "prettyprint.h"

using namespace std;

class Solution {
private:
  int N, Q;
  vector<int> A;
  vector<int> prefix_sum;
  vector<pair<int, int>> range;

public:
  Solution() {
    cin >> N >> Q;
    A.resize(N + 1, 0);
    prefix_sum.resize(N + 1, 0);
    range.resize(Q, { 0, 0 });

    for (int i = 1; i <= N; ++i) {
      cin >> A[i];
    }

    for (int i = 0; i < Q; ++i) {
      cin >> range[i].first >> range[i].second;
    }
  }

  void solve() {
    for (int i = 1; i <= N; ++i) {
      prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }

    cout << prefix_sum << endl;

    for (int i = 0; i < Q; ++i) {
      auto [L, R] = range[i];
      cout << prefix_sum[R] - prefix_sum[L - 1] << endl;
    }
  }
};

int main() {
  auto s = Solution();
  s.solve();

  return 0;
}
