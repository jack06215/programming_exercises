#include <iostream>
#include <vector>
#include <numeric>
#include "../prettyprint.h"

class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        int sum = 0;
        int prefix_min = 0, prefix_max = 0;
        for (auto& val: nums) {
            sum += val;
            prefix_min = std::min(prefix_min, sum);
            prefix_max = std::max(prefix_max, sum);
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