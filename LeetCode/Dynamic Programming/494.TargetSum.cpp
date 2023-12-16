#include <vector>
#include <iostream>
#include <numeric>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();
        const int sum = accumulate(begin(nums), end(nums), 0);
        if (sum < abs(target) || (target + sum) % 2 != 0) {
            return 0;
        }
        const int offset = sum;
        vector<vector<int>> dp(n + 1, vector<int>(sum + offset + 1, 0));
        dp[0][offset] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = nums[i]; j < 2 * sum + 1 - nums[i]; j++) {
                if (dp[i][j]) {
                    dp[i + 1][j + nums[i]] += dp[i][j];
                    dp[i + 1][j - nums[i]] += dp[i][j];
                }
            }
        }
        return dp.back()[target + offset];
    }
};
