#include <vector>
#include <iostream>
#include <queue>

#include "../../prettyprint.h"
#include "../../codec.h"

using namespace std;

class Solution {
    const vector<pair<int, int>> directions = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    bool check_boundary(int i, int j, int max_i, int max_j) {
        return (0 <= i && i < max_i) && (0 <= j && j < max_j);
    }

    void flip(int i, int j, vector<vector<int>>& grid, const int n_rows, const int n_cols) {
        grid[i][j] = 2;
        for (auto [dx, dy] : directions) {
            int ni = i + dx;
            int nj = j + dy;
            if (check_boundary(ni, nj, n_rows, n_cols) && grid[ni][nj] == 1) {
                flip(ni, nj, grid, n_rows, n_cols);
            }
        }
    }


public:
    int shortestBridge(vector<vector<int>>& grid) {
        const int n_rows = grid.size();
        const int n_cols = grid[0].size();
        queue<vector<int>> bfs;

        bool flag = true;
        for (int i = 0; i < n_rows; i++) {
            if (flag) {
                for (int j = 0; j < n_cols; j++) {
                    if (grid[i][j] == 1) {
                        flip(i, j, grid, n_rows, n_cols);
                        flag = false;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (grid[i][j] == 1) {
                    bfs.push({ i, j, 0 });
                }
            }
        }

        while (!bfs.empty()) {
            auto land = bfs.front();
            bfs.pop();
            int i = land[0];
            int j = land[1];
            int d = land[2];
            for (auto [dx, dy] : directions) {
                int ni = i + dx;
                int nj = j + dy;
                if (check_boundary(ni, nj, n_rows, n_cols)) {
                    if (grid[ni][nj] == 0) {
                        grid[ni][nj] = 1;
                        bfs.push({ ni, nj, d + 1 });
                    }
                    else if (grid[ni][nj] == 2) {
                        return d;
                    }
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char* argv[]) {
    vector<vector<int>> grid = read2DVectorFromString("[[0,1,0],[0,0,0],[0,0,1]]");
    cout << Solution().shortestBridge(grid) << endl;

    return 0;
}
