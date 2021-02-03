#define CATCH_CONFIG_MAIN

#include <iostream>
#include <vector>
#include "solution.h"
#include "../catch.hpp"

// int main() {
//     Solution s;
//     std::vector<int> people;
//     int limit;

//     people = {1,2}, limit = 3;
//     std::cout << s.numRescueBoats(people, limit) << std::endl;

//     people = {3,2,2,1}, limit = 3;
//     std::cout << s.numRescueBoats(people, limit) << std::endl;

//     people = {3,5,3,4}, limit = 5;
//     std::cout << s.numRescueBoats(people, limit) << std::endl;

//     return 0;
// }

TEST_CASE("881. Boats to Save People", "[numRescueBoats]")
{
    Solution s;
    std::vector<int> people;
    int limit;

    people = {1,2}, limit = 3;
    REQUIRE( (s.numRescueBoats(people, limit) == 1) );

    people = {3,2,2,1}, limit = 3;
    REQUIRE( (s.numRescueBoats(people, limit) == 3) );

    people = {3,5,3,4}, limit = 5;
    REQUIRE( (s.numRescueBoats(people, limit) == 4) );
}