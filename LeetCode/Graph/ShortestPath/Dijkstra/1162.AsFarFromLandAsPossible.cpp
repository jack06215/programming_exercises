#include <vector>
#include <queue>
#include <iostream>
#include "../../prettyprint.h"
#include "../../codec.h"

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> bfs, next;
        int step = 0;

        const int n_rows = grid.size();
        const int n_cols = grid[0].size();

        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (grid[i][j] == 1) {
                    bfs.push({ i + 1, j });
                    bfs.push({ i - 1, j });
                    bfs.push({ i, j + 1 });
                    bfs.push({ i, j - 1 });
                }
            }
        }

        while (!bfs.empty()) {
            step++;
            while (!bfs.empty()) {
                auto [i, j] = bfs.front();
                bfs.pop();
                if (i >= 0 && j >= 0 && i < n_rows && j < n_cols && grid[i][j] == 0) {
                    grid[i][j] = step;
                    next.push({ i + 1, j });
                    next.push({ i - 1, j });
                    next.push({ i, j + 1 });
                    next.push({ i, j - 1 });
                }
            }
            swap(next, bfs);
        }
        return step == 1 ? -1 : step - 1;
    }
};


int main(int argc, const char* argv[]) {
    vector<vector<int>> grid = read2DVectorFromString("[[1,0,1],[0,0,0],[1,0,1]]");

    cout << grid << endl;

    return 0;
}
