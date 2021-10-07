#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "solution_twoPointer.h"
#include <iostream>
#include <vector>


TEST_CASE("53. Maximum Subarray", "[maxSubArray]")
{
    Solution s;
    std::vector<int> nums;

    nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    REQUIRE( (s.maxSubArray(nums) == 6) );

    nums = {1};
    REQUIRE( (s.maxSubArray(nums) == 1) );

    nums = {0};
    REQUIRE( (s.maxSubArray(nums) == 0) );

    nums = {-1};
    REQUIRE( (s.maxSubArray(nums) == -1) );
}