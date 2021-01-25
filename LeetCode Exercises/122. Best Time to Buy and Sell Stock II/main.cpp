#define CATCH_CONFIG_MAIN
#include <iostream>
#include "solution.h"
#include "../catch.hpp"


TEST_CASE("122. Best Time to Buy and Sell Stocks II", "[maxProfit]")
{
    Solution s;
    std::vector<int> prices;
    
    prices = {7,1,5,3,6,4};
    REQUIRE( (s.maxProfit(prices) == 7) );

    prices = {1,2,3,4,5};
    REQUIRE( (s.maxProfit({prices}) == 4) );

    prices = {7,6,4,3,1};
    REQUIRE( (s.maxProfit(prices) == 0) );

    
}