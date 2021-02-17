#define CATCH_CONFIG_MAIN

#include "../catch_amalgamated.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <iterator>
#include <iostream>
#include <vector>
#include <iostream>

template <class FwdIt, class Compare = std::less<>>
void insertion_sort(FwdIt first, FwdIt last, Compare cmp = Compare{}) {
    for (auto it = first; it != last; ++it) {
        auto const insertion = std::upper_bound(first, it, *it, cmp);
        std::rotate(insertion, it, std::next(it)); 
    }
}

TEST_CASE("70. Climbing Stairs", "[climbStairs]") {
    std::vector<int> arr{4, 8, 6, -1, -2, -3, -1, 3, 4, 5};

    BENCHMARK("Fibonacci 20") {
        return insertion_sort(begin(arr), end(arr));
    };
    // REQUIRE( (s.climbStairs(2) == 2) );
    // REQUIRE( (s.climbStairs(3) == 3) );
}