#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <iostream>
#include <vector>

class SolutionDP {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class SolutionResursive {
public:
    int climbStairs(int n) {
        if (n == 0 | n == 1) {
            return 1;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

TEST_CASE("70. Climbing Stairs", "[climbStairs]")
{
    SolutionResursive s;

    REQUIRE( (s.climbStairs(2) == 2) );
    REQUIRE( (s.climbStairs(3) == 3) );
}