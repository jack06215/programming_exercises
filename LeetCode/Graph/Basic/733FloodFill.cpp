#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include "../../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n_rows = image.size();
        n_cols = image[0].size();
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void dfs(vector<vector<int>>& image, int row, int col, int oldColor, int newColor) {
        // hit boundary
        if (row >= n_rows || row < 0 || col >= n_cols || col < 0) {
            return;
        }
        // no need to fill
        if (image[row][col] != oldColor || image[row][col] == newColor) {
            return;
        }

        image[row][col] = newColor;
        dfs(image, row + 1, col, oldColor, newColor);
        dfs(image, row - 1, col, oldColor, newColor);
        dfs(image, row, col + 1, oldColor, newColor);
        dfs(image, row, col - 1, oldColor, newColor);
    }
private:
    int n_rows;
    int n_cols;
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n_rows = image.size();
        int n_cols = image[0].size();
        int oldColor = image[sr][sc];
        if (newColor == oldColor) {
            return image;
        }

        stack<pair<int, int>> dfs;
        dfs.push({ sr, sc });
        while (!dfs.empty()) {
            auto [row, col] = dfs.top();
            dfs.pop();
            if (image[row][col] == oldColor) {
                image[row][col] = newColor;
            }
            if (row >= 1 && image[row - 1][col] == oldColor) {
                dfs.push({ row - 1, col });
            }
            if (row + 1 < n_rows && image[row + 1][col] == oldColor) {
                dfs.push({ row + 1, col });
            }
            if (col >= 1 && image[row][col - 1] == oldColor) {
                dfs.push({ row, col - 1 });
            }
            if (col + 1 < n_cols && image[row][col + 1] == oldColor) {
                dfs.push({ row, col + 1 });
            }
        }
        return image;
    }
};


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        const int n_rows = image.size();
        const int n_cols = image[0].size();
        const int oldColor = image[sr][sc];
        if (newColor == oldColor) {
            return image;
        }
        queue<pair<int, int>> bfs;
        bfs.push({ sr,sc });
        while (!bfs.empty()) {
            auto [row, col] = bfs.front();
            bfs.pop();
            if (image[row][col] == oldColor) {
                image[row][col] = newColor;
            }
            if (row >= 1 && image[row - 1][col] == oldColor) {
                bfs.push({ row - 1, col });
            }
            if (row + 1 < n_rows && image[row + 1][col] == oldColor) {
                bfs.push({ row + 1, col });
            }
            if (col >= 1 && image[row][col - 1] == oldColor) {
                bfs.push({ row, col - 1 });
            }
            if (col + 1 < n_cols && image[row][col + 1] == oldColor) {
                bfs.push({ row, col + 1 });
            }
        }
        return image;
    }
};

