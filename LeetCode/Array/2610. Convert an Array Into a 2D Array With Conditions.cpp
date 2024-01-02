#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> frequency(nums.size() + 1, 0);
        vector<vector<int>> result;
        for (int num : nums) {
            int& row_index = frequency[num];
            if (row_index >= result.size()) {
                result.push_back({});
            }
            result[row_index].push_back(num);
            row_index++;
        }

        return result;
    }
};


