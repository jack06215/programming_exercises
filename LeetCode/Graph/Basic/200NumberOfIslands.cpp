#include <vector>
#include <iostream>
#include "../../prettyprint.h"

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n_row = grid.size();
        int n_col = n_row ? grid[0].size() : 0;
        int numIsland = 0;
        for (int i = 0; i < n_row; i++) {
            for (int j = 0; j < n_col; j++) {
                if (grid[i][j] == '1') {
                    numIsland++;
                    dfs(grid, i, j);
                }
            }
        }
        return numIsland;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};
