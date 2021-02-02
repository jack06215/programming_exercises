#include <vector>
#include <utility>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};