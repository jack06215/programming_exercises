#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "solution.h"
#include <iostream>
#include <vector>


TEST_CASE("167. Two Sum II - Input array is sorted", "[twoSum]")
{
    Solution s;
    std::vector<int> nums;
    std::vector<int> ans;
    int target;

    nums = {2,7,11,15};
    target = 9;
    ans = {1,2};
    REQUIRE( (s.twoSum(nums, target) == ans) );

    nums = {2,3,4};
    target = 6;
    ans = {1,3};
    REQUIRE( (s.twoSum(nums, target) == ans) );

    nums = {-1,0};
    target = -1;
    ans = {1,2};
    REQUIRE( (s.twoSum(nums, target) == ans) );
}