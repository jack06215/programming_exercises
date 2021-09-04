#define CATCH_CONFIG_MAIN
#include <vector>
#include <utility>
#include <iostream>
#include "../catch.hpp"

class Solution {
public:
    int maxProfit(std::vector<int> prices) {
        int s0 = -prices[0];
        int s1 = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            s0 = std::max(s0, -prices[i]);
            s1 = std::max(s1, prices[i] + s0);
        }
        return std::max(0, s1);
    }
};

TEST_CASE("Best time to sell stock") {
	Solution s;
	REQUIRE( s.maxProfit(std::vector<int>{ 7, 1, 5, 3, 6, 4 }) == 5 );
	REQUIRE( s.maxProfit(std::vector<int>{ 7, 6, 4, 3, 1 }) == 0 );
}
