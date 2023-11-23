#include <iostream>
#include <vector>
#include <tuple>

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
    vector<vector<int>> snow(H + 2, vector<int>(W + 2, 0));

    for (int i = 0; i < N; i++) {
      int a, b, c, d;
      tie(a, b, c, d) = make_tuple(A[i], B[i], C[i], D[i]);
      snow[a][b]++;
      snow[a][d + 1]--;
      snow[c + 1][b]--;
      snow[c + 1][d + 1]++;
    }

    // For the horizontal prefix sum, iterate up to H + 1 for rows and W for columns.
    for (int i = 0; i < H + 1; i++) {
      for (int j = 0; j < W + 1; j++) {
        snow[i][j + 1] += snow[i][j];
      }
    }

    // For the vertical prefix sum, iterate up to H for rows and W + 1 for columns.
    for (int i = 0; i < H + 1; i++) {
      for (int j = 0; j < W + 1; j++) {
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
