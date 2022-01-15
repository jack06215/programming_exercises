#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

TEST_CASE("70. Climbing Stairs", "[climbStairs]") {
    REQUIRE((Solution().climbStairs(2) == 2));
    REQUIRE((Solution().climbStairs(3) == 3));
}