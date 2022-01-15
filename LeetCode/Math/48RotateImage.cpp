#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose
        const int size = matrix.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse right to left
        for (auto& v : matrix) {
            std::reverse(v.begin(), v.end());
        }
    }
};

class Solution {
public:
    void rotate_anticlockwise(vector<vector<int>>& matrix) {
        // reverse left to right
        for (auto& v : matrix) {
            std::reverse(v.begin(), v.end());
        }

        // transpose
        const int size = matrix.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

