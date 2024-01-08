#include <vector>
#include <iostream>
#include "../codec.h"

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

int main() {
    auto matrix = read2DVectorFromString("[[1,3,5,7],[10,11,16,20],[23,30,34,60]]");
    auto solution = Solution();
    cout << boolalpha << solution.searchMatrix(matrix, 3) << endl;
    return 0;
}
