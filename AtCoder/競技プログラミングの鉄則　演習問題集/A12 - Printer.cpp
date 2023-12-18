#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
private:
  int N;
  uint64_t K;
  vector<int> A;

  bool check(uint64_t time) {
    uint64_t count = 0;
    for (int printer : A) {
      count += time / printer;
    }
    return count >= K;
  }
public:
  Solution() {
    cin >> N >> K;
    A.resize(N);
    for (auto& x : A) {
      cin >> x;
    }
  }

  void solve() {
    uint64_t left = 1;
    uint64_t right = 1e10;
    while (left < right) {
      uint64_t mid = left + (right - left) / 2;
      if (check(mid)) {
        right = mid;
      }
      else {
        left = mid + 1;
      }
    }
    cout << left << endl;
  }
};

int main() {
  auto solution = Solution();
  solution.solve();
}
