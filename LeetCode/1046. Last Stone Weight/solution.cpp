#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include <queue>
#include "../catch.hpp"

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if (x > y) {
                pq.push(x - y);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};

TEST_CASE("1046. Last Stone Weight") {
    Solution s = Solution();
    REQUIRE( 
        s.lastStoneWeight(
            vector<int>{2, 7, 4, 1, 8, 1}
        ) == 1 
    );
}