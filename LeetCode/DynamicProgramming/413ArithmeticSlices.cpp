#include <vector>
#include <iostream>
#include <numeric>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int len = nums.size();
        if (len < 3) {
            return 0;
        }
        vector<int> dp(len, 0);
        for (int i = 2; i < len; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        int res =  accumulate(begin(dp), end(dp), 0);
        return res;
    }
};

int main() {
    auto nums = stringToIntVector("[1,2,3,4]");
    cout << Solution().numberOfArithmeticSlices(nums) << endl;
    return 0;
}
