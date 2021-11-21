#include <vector>
#include <iostream>
#include "../prettyprint.h"

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
                    eraseIslands(grid, i, j);
                }
            }
        }
        return numIsland;
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        bool boundary = (i < 0 || i >= rows) || (j < 0 || j >= cols);
        bool visited = grid[i][j] == '0';
        if (boundary || visited) {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};