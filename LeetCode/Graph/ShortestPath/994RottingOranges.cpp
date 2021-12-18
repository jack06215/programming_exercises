#include <queue>
#include <vector>
#include <iostream>
#include "../../prettyprint.h"
#include "../../codec.h"

using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        enum state { processed = -1, empty, fresh, rotten };
        
        int total_fresh = 0;
        queue<pair<int, int>> bfs;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int orange = grid[i][j];
                if (orange == state::fresh) {
                    total_fresh++;
                }
                else if (orange == state::rotten) {
                    bfs.push({ i, j });
                    orange = state::processed;
                }
            }
        }
        if (!total_fresh) {
            return 0;
        }

        // bfs to rot all oranges, 1 minute for each iteration
        while (!bfs.empty()) {
            int queue_size = bfs.size();
            for (int i = 0; i < queue_size; i++) {
                auto [row, col] = bfs.front();
                bfs.pop();

                // now rotton left, right, below, above
                const vector<pair<int, int>> adj{ {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
                for (auto [dx, dy] : adj) {
                    // rotton adjacent orange
                    int offset_row = row + dx;
                    int offset_col = col + dy;

                    // boundary chek
                    if (offset_row >= 0 && offset_row < rows &&
                        offset_col >= 0 && offset_col < cols) {
                        int& orange = grid[offset_row][offset_col];
                        // if the orange is already rotton or it is empty, skip it
                        if (orange == state::processed || orange == state::empty) {
                            continue;
                        }

                        // or if it is a fresh orange, it become rotton,
                        // in which we should add to it to rotton list for next iteration
                        else if (orange == state::fresh) {
                            total_fresh = total_fresh - 1;
                            orange = state::rotten;
                            bfs.push({ offset_row, offset_col });
                        }
                    }
                }
            }
            res = res + 1;
            if (total_fresh == 0) {
                break;
            }
        }
        return total_fresh ? -1 : res;
    }
};

int main(int argc, char const* argv[]) {
    auto grid = read2DVectorFromString("[[2,1,1],[1,1,0],[0,1,1]]");
    Solution s;
    cout << s.orangesRotting(grid) << endl;
    return 0;
}

