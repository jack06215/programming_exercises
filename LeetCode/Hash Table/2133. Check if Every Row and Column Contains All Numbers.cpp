#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_set<int> row_check;
        unordered_set<int> col_check;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                col_check.insert(matrix[j][i]);
                row_check.insert(matrix[i][j]);
            }
            if (col_check.size() != n || row_check.size() != n) {
                return false;
            }
            row_check.clear();
            col_check.clear();
        }
        return true;
    }
};
