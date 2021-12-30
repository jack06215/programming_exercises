#include <vector>
#include <iostream>
#include <numeric>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        int halfSum = totalSum / 2;
        if (totalSum & 1) {
            return false;
        }
        vector<bool> dp(halfSum + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int j = halfSum; j >= num; j--) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
        }
        return dp[halfSum];
    }
};

int main() {


    return 0;
}
