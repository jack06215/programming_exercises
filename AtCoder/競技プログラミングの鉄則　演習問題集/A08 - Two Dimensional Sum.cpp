#include <iostream>
#include <vector>
#include <tuple>
#include "../../prettyprint.h"

using namespace std;

class Solution {
private:
    int H, W, Q;
    vector<vector<int>> grid;
    vector<tuple<int, int, int, int>> points;

public:
    Solution() {
        cin >> H >> W;
        grid.resize(H + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                cin >> grid[i][j];
            }
        }
        cin >> Q;
        points.resize(Q);
        for (int i = 0; i < Q; ++i) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            points[i] = make_tuple(x1, y1, x2, y2);
        }
    }

    void solve() {
        vector<vector<int>> prefix_sum(H + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                prefix_sum[i][j] = grid[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
            }
        }
        cout << prefix_sum << endl;
        for (int i = 0; i < Q; ++i) {
            int A, B, C, D;
            tie(A, B, C, D) = points[i];
            int sum = prefix_sum[C][D] - prefix_sum[C][B - 1] - prefix_sum[A - 1][D] + prefix_sum[A - 1][B - 1];
            cout << sum << endl;
        }
    }
};

int main() {
    auto s = Solution();
    s.solve();
    return 0;
}
