#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "solution.h"
#include <iostream>


TEST_CASE("1137. N-th Tribonacci Number", "[tribonacci]")
{
    Solution s;

    REQUIRE( (s.tribonacci(4) == 4) );
    REQUIRE( (s.tribonacci(25) == 1389537) );
}