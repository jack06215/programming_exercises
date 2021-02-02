#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "solution.h"
#include <iostream>


TEST_CASE("70. Climbing Stairs", "[climbStairs]")
{
    Solution s;

    REQUIRE( (s.tribonacci(4) == 4) );
}