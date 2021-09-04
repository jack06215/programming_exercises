#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "solution.h"
#include <iostream>
#include <vector>


TEST_CASE("Minimun Cost to Cut a Stick", "[rodCut_dp]")
{
    std::vector<int> nums;

    nums = {1, 5, 8, 9, 10, 17, 17, 20};
    REQUIRE( (rodCut_dp(nums, nums.size()) == 22) );

    nums = {3, 5, 8, 9, 10, 17, 17, 20};
    REQUIRE( (rodCut_dp(nums, nums.size()) == 24) );
}