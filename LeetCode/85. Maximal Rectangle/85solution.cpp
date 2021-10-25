#include <iostream>
#include <vector>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int n_rows = matrix.size();
        int n_cols = matrix[0].size();

        vector<int> height(n_cols + 1, 0);
        int res = 0;
        for (int i = 0; i < n_rows; ++i) {
            vector<int> stk;
            for (int j = 0; j < n_cols + 1; ++j) {
                if (j < n_cols) {
                    height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
                }
                while (!stk.empty() && height[stk.back()] >= height[j]) {
                    int cur = stk.back(); stk.pop_back();
                    int width = stk.empty() ? j : (j - stk.back() - 1);
                    res = max(res, height[cur] * width);
                }
                cout << height << endl;
                stk.push_back(j);
            }
            cout << endl;
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<vector<char>> matrix = { {'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'} };
    cout << s.maximalRectangle(matrix) << endl;
    return 0;
}

