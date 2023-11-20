#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int H, W, N;
  vector<int> A, B, C, D;
public:
  Solution() {
    cin >> H >> W >> N;
    A.resize(N);
    B.resize(N);
    C.resize(N);
    D.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
  }

  void solve() {
    vector<vector<int>> snow(H + 3, vector<int>(W + 3, 0));

    for (int i = 0; i < N; i++) {
      snow[A[i]][B[i]]++;
      snow[A[i]][D[i] + 1]--;
      snow[C[i] + 1][B[i]]--;
      snow[C[i] + 1][D[i] + 1]++;
    }

    // Horizontal Prefix Sum
    for (int i = 0; i < H + 2; i++) {
      for (int j = 0; j < W + 2; j++) {
        snow[i][j + 1] += snow[i][j];
      }
    }

    // Vertical Prefix Sum
    for (int i = 0; i < H + 2; i++) {
      for (int j = 0; j < W + 2; j++) {
        snow[i + 1][j] += snow[i][j];
      }
    }

    // Output the final snow accumulation
    for (int i = 1; i <= H; ++i) {
      for (int j = 1; j <= W; ++j) {
        cout << snow[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  auto s = Solution();
  s.solve();
  return 0;
}
