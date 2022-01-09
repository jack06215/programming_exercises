#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() * matrix[0].size();

        const int stride = matrix[0].size();
        auto get_index = [&](int index) -> pair<int, int> {
            return { index / stride, index % stride };
        };

        while (left < right) {
            int mid = (right + left) / 2;
            auto [i, j] = get_index(mid);

            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
};
