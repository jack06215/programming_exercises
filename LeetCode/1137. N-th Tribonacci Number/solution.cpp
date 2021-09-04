#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include <iostream>
#include <vector>

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return n;
        }
        std::vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};



TEST_CASE("1137. N-th Tribonacci Number", "[tribonacci]")
{
    Solution s;

    REQUIRE( (s.tribonacci(4) == 4) );
    REQUIRE( (s.tribonacci(25) == 1389537) );
}
