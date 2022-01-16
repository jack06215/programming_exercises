#include <vector>

using namespace std;

/*
    DP: dp[0][i] is the minimum value of subarray ending in index i
        dp[1][i] is the maximum value of subarray ending in index i.

    The formula is:
        1) dp[0][i] = min(dp[0][i - 1] + nums[i], nums[i]);
        2) dp[1][i] = max(dp[1][i - 1] + nums[i], nums[i]).

    Finally return go through each element and find out the max absolute value.
*/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int size = nums.size();
        int res = 0;
        vector<vector<int>> dp(2, vector<int>(size + 1));
        for (int i = 1; i <= size; i++) {
            dp[0][i] = min(dp[0][i - 1] + nums[i - 1], nums[i - 1]);
            dp[1][i] = max(dp[1][i - 1] + nums[i - 1], nums[i - 1]);
        }

        for (int i = 0; i <= size; i++) {
            res = max({ res, abs(dp[0][i]), abs(dp[1][i]) });
        }
        return res;
    }
};

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefix_sum = 0;
        int prefix_min = 0;
        int prefix_max = 0;
        for (auto& val : nums) {
            prefix_sum += val;
            prefix_min = min(prefix_min, prefix_sum);
            prefix_max = max(prefix_max, prefix_sum);
        }
        return prefix_max - prefix_min;
    }
};
