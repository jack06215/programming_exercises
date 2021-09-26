#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = rows ? matrix[0].size() : 0;
        
        // up-right direction
        int x = -1;
        int y = 1;
        
        vector<int> res;
        int i = 0;
        int j = 0;
        while (res.size() < rows * cols) {
            // if reach boundary
            if (i == rows || j == cols || j < 0 || i < 0) {
                // from upward to downward movement and vice versa
                swap(x, y);
                
                // out of boundary
                if (j == cols) {
                    i = i + 2;
                    j = j - 1;
                }
                else if (i == rows) {
                    j = j + 2;
                    i = i - 1;
                }
                else {
                    i = i + (i < 0);
                    j = j + (j < 0);
                }
            }
            res.push_back(matrix[i][j]);            
            // move one step forward
            i = i + x;
            j = j + y;
        }
        return res;
    }
};
