#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include "../prettyprint.h"

class Solution {
public:
  int minElements(std::vector<int>& nums, int limit, int goal) {
    int64_t diff = std::abs(goal - std::accumulate(begin(nums), end(nums), 0LL));
    return (diff + limit - 1) / limit;
  }
};

int main(){
    std::vector<int> input;
    int limits;
    int goal;
    Solution s = Solution();

    input = {1,-1,1};
    limits = 3;
    goal = -4;

    std::cout << s.minElements(input, limits, goal) << std::endl;
    return 0;
}