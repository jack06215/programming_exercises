#include <vector>
#include <iostream>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

/*
    // nums = [1, 2, 3], target = 4
    Patterns:
    dp[0] = 1                       # there is 1 way to have target = 0, i.e. not use anything from the array.
    dp[1] = dp[0]                   # 
    dp[2] = dp[1] + dp[0]
    dp[3] = dp[2] + dp[1] + dp[0]
    dp[4] = dp[3] + dp[2] + dp[1]
    Formula:
    dp[i] = sum(dp[i-j]) where i is the current target, and j is in range(nums)
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (auto curr : nums) {
                if (i - curr >= 0) {
                    dp[i] = dp[i] + dp[i - curr];
                }
            }
            cout << dp << endl;
        }
        cout << endl << dp << endl;
        return dp[target];
    }
};

int main() {
    vector<int> nums = stringToIntVector("[1,2,3]");
    cout << Solution().combinationSum4(nums, 4) << endl;
    return 0;
}
