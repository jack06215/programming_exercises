#include <iostream>
#include <vector>
#include <numeric>
#include "../prettyprint.h"

class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        int prefix_sum, prefix_min, prefix_max = 0;
        for (auto& val: nums) {
            prefix_sum += val;
            prefix_min = std::min(prefix_min, prefix_sum);
            prefix_max = std::max(prefix_max, prefix_sum);
        }
        return prefix_max - prefix_min;
    }
};

int main() {
    std::vector<int> input;
    Solution s = Solution();

    input = {1, -3, 2, 3, -4};
    std::cout << s.maxAbsoluteSum(input) << std::endl;

    return 0;
}