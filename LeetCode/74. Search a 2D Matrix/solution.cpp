#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

/*
row    = index / width
column = index % width
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        
        int n_cols = matrix[0].size();
        int left = 0;
        int right = matrix.size() * n_cols - 1;
        
        while (left <= right) {
            int mid = (right + left) / 2;
            auto [i, j] = to_2d_coordinate(mid, n_cols);
            
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
private:
    pair<int, int> to_2d_coordinate(int index, int stride) {
        return { index / stride, index % stride };
    }
};
