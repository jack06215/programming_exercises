#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n_rows = matrix.size();
        const int n_cols = matrix[0].size();
        return _searchMatrix(matrix, target, 0, n_rows - 1, 0, n_cols - 1);
    }
private:
    bool _searchMatrix(vector<vector<int>>& matrix, int target, int startRow, int endRow, int startCol, int endCol) {
        // base case
        if (startRow > endRow || startCol > endCol) {
            return false;
        }
        // find middle of the matrix
        const int middleRow = ((endRow - startRow) / 2) + startRow;
        const int middleCol = ((endCol - startCol) / 2) + startCol;

        // if we found the target we solve the problem, so return true  
        if (matrix[middleRow][middleCol] == target) {
            return true;
        }

        // it is the "devide" step, basically, we define the recurrence relation for the recursion function.
        // let m - is our middle point.
        if (matrix[middleRow][middleCol] < target) {
            // if m less than the target than all points before m also less tha target (marked by x)
            // so we only need look through cells marked by 1 and 2
            // x x x 2 2
            // x x x 2 2
            // x x m 2 2
            // 1 1 1 1 1
            // 1 1 1 1 1
            return _searchMatrix(matrix, target, middleRow + 1, endRow, startCol, endCol) ||
                _searchMatrix(matrix, target, startRow, middleRow, middleCol + 1, endCol);
        }
        else {
            // if m greater than the target than all points after m also greater than the target (marked by x)
            // so we only need look through cells marked by 1 and 2
            // 1 1 2 2 2
            // 1 1 2 2 2
            // 1 1 m x x
            // 1 1 x x x
            // 1 1 x x x
            return _searchMatrix(matrix, target, startRow, endRow, startCol, middleCol - 1) ||
                _searchMatrix(matrix, target, startRow, middleRow - 1, middleCol, endCol);
        }
    }
};