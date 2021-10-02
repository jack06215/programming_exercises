#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int n = nums.size();
        const int sum = std::accumulate(nums.begin(),nums.end(), 0);
        if (sum < S) return 0;
        const int offset = sum;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(sum + offset + 1, 0));
        dp[0][offset] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = nums[i]; j < 2 * sum + 1 - nums[i]; j++) {
                if (dp[i][j]) {
                    dp[i + 1][j + nums[i]] += dp[i][j];
                    dp[i + 1][j - nums[i]] += dp[i][j];
                }
            }
        }
        return dp.back()[S + offset];
    }
};
